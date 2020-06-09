#include"WordList.h"

WordList::WordList(string filename)
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

string WordList::get_word(int index)
{
    return words[index];
}

int WordList::get_size()
{
    return words.size();
}