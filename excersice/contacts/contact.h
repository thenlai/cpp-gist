#ifndef _CONTACT_H
#define _CONTACT_H

#include <vector>
#include "people.h"

class Contact {
    private:
        std::vector<People> data;
        char *dbName;
    public:
        Contact(const char *filename);
        bool read();
        bool show(void (*callback)(People&));
        bool add(People &p);
        bool save();
        bool edit(People &p);
        bool remove();
        std::vector<People> all();
        std::vector<People> search(int field, std::string keyword);
};

#endif