#include <iostream>

class Base1 {
public:
  void fn() {
    std::cout << "base 1\n";
  }
  void fn1() {
    std::cout << "base 1, fn 1\n";
  }
};

class Base2 {
private:
  void fnPrivate() {
    std::cout << "base 2 private";
  }
  // 同名同参的函数在多继承时会冲突
  // ** 不分public private
  /*
  void fn() {
    std::cout << "base 2 private";
  }
  */
public:
  // 同名同参的函数在多继承时会冲突
  /*
  void fn() {
    std::cout << "base 2";
  }
  */
  void fn2() {
    std::cout << "base 2, fn 2\n";
  }
};

class Derived : public Base1, public Base2 {
};

int main() {
  Derived d = Derived();
  d.fn();
  d.fn1();
  d.fn2();
  return 0;
}