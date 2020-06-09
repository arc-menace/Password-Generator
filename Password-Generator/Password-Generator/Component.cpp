#include"Component.h"

Component::Component(TYPE i_type, WordList* i_words) : words(i_words), type(i_type)
{
    switch (type) {
    case TYPE::STRING:
        word = words->get_word(rand() % (words->get_size() - 1)); //Define Word
        toupper(word[0]);
        break;
    case TYPE::CHAR:
        character = SPECIAL_CHARS[rand() % 9]; //[0 - 9]
        break;
    case TYPE::INT:
        number = rand() % 9989 + 10; //[10 - 9999]
        break;
    default:
        exit(1);
        break;
    }
}

void Component::print()
{
    switch (type)
    {
    case TYPE::STRING:
        cout << word;
        break;
    case TYPE::INT:
        cout << number;
        break;
    case TYPE::CHAR:
        cout << character;
        break;
    default:
        exit(1);
        break;
    }
}

TYPE Component::get_type()
{
    return type;
}