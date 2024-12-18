#include <iostream>
#include <Windows.h>
#include "Evstring.hpp"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Evstring a();
	Evstring b(31);
	Evstring c("Hello World!");

	unsigned int size = c.getSize();
	for (unsigned short i = 0; i < size; i++) {
		std::cout << *(c.getWord() + i);
	}

	return 0;
}