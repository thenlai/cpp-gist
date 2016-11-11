#include "people.h"

People::People() {
    // empty
}

People::People(
    std::string name,
    std::string telephone,
    std::string address) {
    this->name = name;
    this->telephone = telephone;
    this->address = address;
}

People::People(std::string line) {
    int numOfTab = 0;
    std::string temp = "";
    std::string::iterator it = line.begin();
    for(; it < line.end(); it++) {
        if (*it == '\t') {
            numOfTab ++;
            switch (numOfTab) {
                case 1: this->name = temp; break;
                case 2: this->telephone = temp; break;
            }
            temp = "";
        } else {
            temp.push_back(*it);
            if (it == line.end()-1) {
                this->address = temp;
            }
        }
    }
}

std::string People::encode() {
    return this->name + '\t' + this->telephone + '\t' + this->address;
}