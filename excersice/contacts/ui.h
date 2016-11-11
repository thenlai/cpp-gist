#ifndef _UI_H
#define _UI_H

#include <fstream>
#include <string>
#include "people.h"
#include "contact.h"

void menu();
void printPeople(People &p);
People getPeople();
int getAction();
void printSearch(std::vector<People> r);

const int ACTIONS_COUNT  = 7;
const static std::string ACTIONS[ACTIONS_COUNT][2] = {
    {"list", "l"},
    {"find", "f"},
    {"add", "a"},
    {"edit", "e"},
    {"delete", "d"},
    {"save", "s"},
    {"exit", "x"}
};

#endif