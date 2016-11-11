#include "ui.h"

void menu() {
    std::cout
    << "Menu:"
    << " 1.list(l),"
    << " 2.find(f),"
    << " 3.add(a),"
    << " 4.edit(e),"
    << " 5.delete(d),"
    << " 6.save(s),"
    << " 7.exit(x)"
    << std::endl;
}

void printPeople(People &p) {
    std::cout
    << "\t" << p.name
    << "\t# " << p.telephone
    << "\t@ " << p.address
    << std::endl;
}

People getPeople() {
    People p;
    std::cout << "name: ";
    std::getline(std::cin, p.name);
    std::cout << "telephone: ";
    std::getline(std::cin, p.telephone);
    std::cout << "address: ";
    std::getline(std::cin, p.address);
    return p;
}

int getAction() {
    std::string action;
    std::getline(std::cin, action);
    for (int i = 0; i < ACTIONS_COUNT; i++) {
        if(action.compare(ACTIONS[i][0]) == 0 || action.compare(ACTIONS[i][1]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

void printSearch(std::vector<People> r) {
    if (r.size() <= 0) {
        std::cout << "no matched records." << std::endl;
        return;
    }
    std::vector<People>::iterator it = r.begin();
    for (; it < r.end(); it++) {
        printPeople(*it);
    }
}