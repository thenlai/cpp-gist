#ifndef _PEOPLE_H
#define _PEOPLE_H

#include <string>

const int FIELD_NAME = 1;
const int FIELD_TELEPHONE = 2;
const int FIELD_ADDRESS = 3;

class People {
    public:
        std::string name;
        std::string telephone;
        std::string address;
        People();
        People(
            std::string name,
            std::string telephone,
            std::string address);
        People(std::string line);
        std::string encode();
};

#endif