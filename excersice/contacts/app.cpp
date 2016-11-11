#include <iostream>
#include "ui.h"

const char *DB = "contacts.txt";

int main() {
    bool end = false;
    Contact model = Contact(DB);
    People t;
    if (model.read()) {
        menu();
        while (!end) {
            std::cout << "do: ";
            std::string input;
            switch (getAction()) {
                case 1:
                    model.show(&printPeople);
                    break;
                case 2:
                    std::cout << "keyword: ";
                    std::getline(std::cin, input);
                    printSearch(model.search(1, input));
                    break;
                case 3:
                    t = getPeople();
                    model.add(t);
                    break;
                case 4:
                    // model.edit();
                    break;
                case 5:
                    // model.remove();
                    break;
                case 6:
                    model.save();
                    break;
                case 7:
                    end = true;
                    break;
                default:
                    std::cout << "Invalid actions. Retry please." << std::endl;
            }
        }
    }
    return 0;
}