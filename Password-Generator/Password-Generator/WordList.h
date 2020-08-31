#ifndef WORDLIST_H
#define WORDLIST_H

#include"global.h"

class WordList
{
    vector<string> words;
public:
    WordList(string filename);

    string get_word(int index);
    int get_size();
};

#endif