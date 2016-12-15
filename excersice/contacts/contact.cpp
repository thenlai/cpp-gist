#include "contact.h"

Contact::Contact(const char *filename) {
    this->dbName = filename;
    this->hasChanged = false;
}

bool Contact::read() {
    std::string line;
    std::ifstream ifs(this->dbName);
    if(ifs.is_open()) {
        while (getline(ifs, line)) {
            if (line.size() == 0)  continue;
            People p = People(line);
            this->data.push_back(p);
        }
        ifs.close();
    }
    return true;
}

bool Contact::show(void (*callback)(People&)) {
    if (this->data.size() <= 0) {
        std::cout << "No contacts recorded.\n";
        return false;
    }
    std::vector<People>::iterator it = this->data.begin();
    for (; it < this->data.end(); it++) {
        callback(*it);
    }
    return true;
}

bool Contact::add(People &p) {
    // if p do not exists, return `true`
    // otherwise return `false`
    this->data.push_back(p);
    this->hasChanged = true;
}

People& Contact::get(int index) {
    return data.at(index);
}

bool Contact::edit(People &p) {
    this->hasChanged = true;
}

bool Contact::remove(int index) {
    this->hasChanged = true;
}

bool Contact::save() {
    if (!this->hasChanged) return false;
    std::ofstream ofs;
    ofs.open(this->dbName);
    if (ofs.is_open()) {
        std::vector<People>::iterator it = this->data.begin();
        for(; it < this->data.end(); it++) {
            ofs.put('\n');
            ofs << it->encode();
        }
        ofs.close();
        this->hasChanged = false;
        return true;
    } else {
        return false;
    }
}

std::vector<People> Contact::search(int field, std::string keyword) {
    std::vector<People> r;
    std::vector<People>::iterator it = this->data.begin();
    for (; it < this->data.end(); it++) {
        if (
            (field == 1 && it->name.compare(keyword) == 0) ||
            (field == 2 && it->telephone.compare(keyword) == 0) ||
            (field == 3 && it->address.compare(keyword) == 0)
        ) {
            r.push_back(*it);
        }
    }
    return r;
}

std::vector<People> *Contact::all() {
    return &(this->data);
}