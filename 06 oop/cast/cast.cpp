#include <iostream>

class Base {
public:
    void fn() {
        std::cout << "base\n";
    }
};
class Derived : public Base {
public:
    void fn() {
        std::cout << "derived\n";
    }
};

int main() {
    Base b = Derived(); // upcast
    b.fn();
    // error
    // can not cast
    // Derived c = Base(); // downcast
    // b.fn();

    Base *pb = new Derived();
    pb->fn();

    // error:
    // can not cast
    // Derived *pd = new Base();
    // pd->fn();

    Base b1 = Base();
    // Java style, grammar error in C++
    // ((Derived) b1).fn();

    Derived d1 = Derived();
    // Java style, grammar error in C++
    // ((Base) d1).fn();
}
