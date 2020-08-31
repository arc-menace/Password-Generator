#ifndef COMPONENT_H
#define COMPONENT_H

#include"global.h"
#include"WordList.h"

class Component
{
    TYPE type;
    string word = "";
    char character = ' ';
    int number = 0;
    WordList* words;
public:
    Component(TYPE i_type, WordList* i_words);
    void print();
    TYPE get_type();
};

#endif
