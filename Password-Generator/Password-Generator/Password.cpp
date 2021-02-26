#include"Password.h"

Password::Password(int num_sections, WordList* i_words) : words(i_words)
{
    components.push_back(new Component(TYPE::INT, words));
    components.push_back(new Component(TYPE::CHAR, words));
    for (int i = 0; i < num_sections - 2; i++)
    {
        components.push_back(new Component(TYPE::STRING, words));
    }
    random_shuffle(components.begin(), components.end());

    print_password();
}

void Password::reroll(int index) //function input starts at 1
{
    index -= 1;
    switch (components[index]->get_type())
    {
    case TYPE::STRING:
        components[index] = new Component(TYPE::STRING, words);
        break;
    case TYPE::INT:
        components[index] = new Component(TYPE::INT, words);
        break;
    case TYPE::CHAR:
        components[index] = new Component(TYPE::CHAR, words);
        break;
    default:
        exit(2);
        break;
    }
    print_password();
}

void Password::shuffle_password()
{
    random_shuffle(components.begin(), components.end());
}

void Password::print_password()
{
    cout << endl << "Sections: ";
    for (unsigned int i = 0; i < components.size(); i++)
    {
        components[i]->print();
        cout << "\t";
    }

    cout << endl << "Password:\t";
    for (unsigned int i = 0; i < components.size(); i++)
    {
        components[i]->print();
    }
    cout << endl;
}