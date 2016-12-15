#include<iostream>

class Base {
	public:
		Base(){}
		void fn() {
			std::cout << "normal base" << std::endl;
		}
		virtual void fnV() {
			std::cout << "virtual base" << std::endl;
		}
};

class Derived: public Base {
	public:
		Derived(){}
		void fn() {
			std::cout << "normal derived" << std::endl;
		}
		void fnV() {
			std::cout << "virtual derived" << std::endl;
		}
};

int main() {
	Base *p = new Derived();
	p->fn();
	p->fnV();
	delete(p);

	Base b = Derived();
	b.fn();
	b.fnV();

	Derived *dp = new Derived();
	dp->fn();
	dp->fnV();
	delete(dp);

	Derived d = Derived();
	d.fn();
	d.fnV();
}