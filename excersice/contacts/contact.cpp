#include "contact.h"

Contact::Contact(const char *filename) {
    dbName = filename;
}

bool Contact::read() {
    std::string line;
    std::ifstream ifs(this->dbName);
    if(ifs.is_open()) {
        while (getline(ifs, line)) {
            this->data.push_back(line);
        }
        ifs.close()
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
    this->data.push_back(p);
}

bool Contact::edit(People &p) {
    //
}

bool Contact::remove() {
    //
}

bool Contact::save() {
    std::ofstream ofs;
    ofs.open(this->dbName);
    if (ofs.is_open()) {
        ofs << "content";
        ofs.close();
        return true;
    } else {
        return false;
    }
}

std::vector<People> Contact::search(int field, std::string keyword) {

}

std::vector<People> Contact::all() {
    return this->data;
}