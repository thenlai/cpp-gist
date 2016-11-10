#ifndef _PEOPLE_H
#define _PEOPLE_H

#include <iostream>

const int FIELD_NAME = 1;
const int FIELD_TELEPHONE = 2;
const int FIELD_ADDRESS = 3;

typedef struct _People {
    std::string name;
    std::string telephone;
    std::string address;
} People;

#endif