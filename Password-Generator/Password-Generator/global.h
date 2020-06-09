#ifndef GLOBAL_H
#define GLOBAL_H

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

enum class TYPE
{
    STRING,
    CHAR,
    INT
};

const double kps = 17042497.3;
/*
    keys per second. can be used to calculate
    how long it would take to brute force crack
    the generated password
*/

#endif