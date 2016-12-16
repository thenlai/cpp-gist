/**
 * override must be compiled with `-std=c++11`
 * g++ -std=c++11 override.cpp
 *
 * `override` specifies that a virtual function overrides another virtual function.
 * it ensures that the function is virtual and is overriding a virtual function from the base class
 * it is **not** a reserved keyword
 */

class A {
    virtual void fn();
    void fn1();
};

class B : A {
    // error, signature not match
    /// void fn() const override;

    // ok
    void fn() override;
    // the same as:
    /// virtual void fn() override;

    // what is the diffence between:
    /// void fn();


    // error, A.fn1() is not virtual
    /// void fn1() override;

    // normal override
    void fn1();
};

int main () {
    return 0;
}