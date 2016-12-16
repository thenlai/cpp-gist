/**
 * since c++11
 * 
 */
class A {
    virtual void fn() final;
};

class B final : A {
    // error:
    void fn() override;
    // or, error:
    // void fn();
};

// error: B is `final`
class C : B {

};

int main() {
    return 0;
}