#include <iostream>

int main(void) {
    char *const a = new char[4];
    for (int i = 0; i < 4; i++) {
        *(a+i) = 'A' + i;
    }

    for (int i = 0; i < 4; i++) {
        std::cout << *(a+i);
    }

    delete a;
}