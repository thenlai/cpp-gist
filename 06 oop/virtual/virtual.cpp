#include<iostream>

class Base {
	public:
		Base(){}
		virtual void print() {
			std::cout << "base";
		}
};

class Derived: public Base {
	public:
		Derived(){}
		void print() {
			std::cout << "Derived";
		}
};

int main() {
	Base *p = new Derived();
	p->print();
}