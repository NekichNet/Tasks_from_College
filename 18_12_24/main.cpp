#include <iostream>
#include <Windows.h>
#include "Evstring.hpp"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Evstring a;
	/*a.getLine();

	unsigned int size = a.getSize();
	for (unsigned short i = 0; i < size; i++) {
		std::cout << *(a.getWord() + i);
	}*/

	return 0;
}