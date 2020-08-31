#ifndef PASSWORD_H
#define PASSWORD_H

#include"global.h"
#include"WordList.h"
#include"Component.h"

class Password
{
    vector<Component*>components;
    WordList* words;

public:
    Password(int num_sections, WordList* i_words);
    void reroll(int index); //function input starts at 1
    void print_password();
};

#endif
