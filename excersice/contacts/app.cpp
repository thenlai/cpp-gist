#include <iostream>
#include <fstream>
#include "contact.h"

const char* DB = "contacts.txt";

void menu() {
    std::cout << "Menu:";
    std::cout << " 1. show,";
    std::cout << " 2. search,";
    std::cout << " 3. add,";
    std::cout << " 4. edit,";
    std::cout << " 5. delete,";
    std::cout << " 6. save,";
    std::cout << " 7. exit";
    std::cout << std::endl;
}

void printPeople(People &p) {
    std::cout << "name: " << p.name;
    std::cout << ", tel: " << p.telephone;
    std::cout << ", address: " << p.address;
    std::cout << std::endl;
}

People getPeople() {
    People p;
    std::cout << "name: ";
    std::cin >> p.name;
    std::cout << "telephone: ";
    std::cin >> p.telephone;
    std::cout << "address: ";
    std::cin >> p.address;
    return p;
}

int main() {
    bool end = false;
    Contact app = Contact(DB);
    People t;
    if (app.read()) {
        while (!end) {
            menu();
            int action;
            std::cin >> action;
            switch (action) {
                case 1:
                    app.show(&printPeople);
                    break;
                case 2:
                    // app.search();
                    break;
                case 3:
                    t = getPeople();
                    app.add(t);
                    break;
                case 4:
                    // app.edit();
                    break;
                case 5:
                    // app.remove();
                    break;
                case 6:
                    app.save();
                    break;
                case 7:
                    end = true;
                    break;
                default:
                    end = true;
                    break;
            }
        }
    }
    return 0;
}