#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <stdlib.h>     
#include <time.h>

using namespace std;

const char SPECIAL_CHARS[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' };

enum TYPE
{
    STRING,
    CHAR,
    INT
};

class WordList
{
    vector<string> words;
public:
    WordList(string filename)
    {
        //Load words in to memory from file
        fstream inf(filename);
        if (!inf)
        {
            cerr << "Error opening file" << endl;
            exit(-1);
        }
        cout << "Loading Words";

        string input;
        while (inf >> input)
        {
            words.push_back(input);
            if (words.size() % 1000 == 0) //Basic loading "animation"
            {
                cout << ".";
            }
        }

        cout << endl << words.size() << " words loaded." << endl;
        inf.close();
    }

    string get_word(int index)
    {
        return words[index];
    }

    int get_size()
    {
        return words.size();
    }
};

class Component
{
    TYPE type;
    string word = "";
    char character = ' ';
    int number = 0;
    WordList* words;
public:
    Component(TYPE i_type, WordList* i_words) : words(i_words), type(i_type)
    {
        switch(type){
        case STRING:            
            word = words->get_word(rand() % (words->get_size() - 1)); //Define Word
            toupper(word[0]);
            break;
        case CHAR:            
            character = SPECIAL_CHARS[rand() % 9]; //[0 - 9]
            break;
        case INT:
            number = rand() % 9989 + 10; //[10 - 9999]
            break;
        default: 
            exit(1);
            break;
        }
    }

    void print()
    {
        switch (type)
        {
        case STRING:
            cout << word;
            break;
        case INT:
            cout << number;
            break;
        case CHAR:
            cout << character;
            break;
        default:
            exit(1);
            break;
        }
    }

    TYPE get_type()
    {
        return type;
    }
};

class Password
{
    vector<Component*>components;
    WordList* words;

public:
    Password(int num_sections, WordList* i_words) : words(i_words)
    {
        components.push_back(new Component(INT, words));
        components.push_back(new Component(CHAR, words));
        for (int i = 0; i < num_sections - 2; i++)
        {
            components.push_back(new Component(STRING, words));
        }
        random_shuffle(components.begin(), components.end());

        print_password();
    }

    void reroll(int index) //function input starts at 1
    {
        index -= 1; 
        switch (components[index]->get_type())
        {
        case STRING:
            components[index] = new Component(STRING, words);
            break;
        case INT:
            components[index] = new Component(INT, words);
            break;
        case CHAR:
            components[index] = new Component(CHAR, words);
            break;
        default:
            exit(2);
            break;
        }
        print_password();
    }

    void print_password()
    {
        cout << endl << "Sections: ";
        for (int i = 0; i < components.size(); i++)
        {
            components[i]->print();
            cout << "\t";
        }

        cout << endl << "Password:\t";
        for (int i = 0; i < components.size(); i++)
        {
            components[i]->print();
        }
        cout << endl;
    }
};


int main()
{  
    const double kps = 17042497.3; 
    /* 
        keys per second. can be used to calculate 
        how long it would take to brute force crack 
        the generated password 
    */
    srand(time(NULL));
    
    cout << "Enter # of Password Sections (Max: 10): " << endl;
    int num_sections = 0;
    cin >> num_sections;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please try again: ";
        cin >> num_sections;
    }

    if (num_sections > 10)
    {
        num_sections = 10;
    }
    else if (num_sections <= 0)
    {
        num_sections = 1;
    }
    

    //Actual program running here
    WordList* words = new WordList("words.txt");
    Password password(num_sections, words);
    
    int change = 0;
    do {
        cout << "To change a component, enter its corresponding index (1 - " << num_sections << ") or 0 to exit: ";
        cin >> change;
        while (cin.fail() || change > num_sections)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please try again: ";
            cin >> change;
        }
        if (change != 0)
        {
            password.reroll(change);
        }
    } while (change != 0);



    return 0;
}