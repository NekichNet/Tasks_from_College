#include <iostream>

class Base {
public:
	// virtual
	void Print() const {
		std::cout << "Ahoy!\n";
	}
};

class Derived : public Base {
public:
	void Print() const {
		std::cout << "Hi!\n";
	}
};

void Print(const Base& obj) {
	obj.Print();
}



int main() {
	Base base;
	Derived derived;
	base.Print();
	derived.Print();
	derived.Base::Print();
	Print(base);
	Print(derived);

	return 0;
}