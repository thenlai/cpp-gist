#ifndef _CONTACT_H
#define _CONTACT_H

#include <iostream>
#include <fstream>
#include <vector>
#include "people.h"

class Contact {
    private:
        std::vector<People> data;
        const char *dbName;
        bool hasChanged;
    public:
        Contact(const char *filename);
        bool read();
        bool show(void (*callback)(People&));
        bool add(People &p);
        bool save();
        bool edit(People &p);
        People& get(int index);
        bool remove(int index);
        std::vector<People> *all();
        std::vector<People> search(int field, std::string keyword);
};

#endif