#include <iostream>
#include <Windows.h>

template <typename ListType>
void print2Dlist(ListType list, unsigned short size_x, unsigned short size_y) {
	for (unsigned short i = 0; i < size_x; i++) {
		for (unsigned short j = 0; j < size_y; j++) {
			std::cout << list[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// TWO TASKS IN ONE SCRIPT

	unsigned const short x = 4, y = 10;
	int list1[x][y], list2[x][y], value;
	
	for (unsigned short i = 0; i < x; i++) {
		std::cout << "Enter " << i << " value: ";
		std::cin >> value;
		for (unsigned short j = 0; j < y; j++) {
			list1[i][j] = value * std::pow(2, j);
			list2[i][j] = value + j;
		}
	}

	std::cout << "\nLists' values are:\n\n";
	print2Dlist(list1, x, y);
	std::cout << std::endl;
	print2Dlist(list2, x, y);

	return 0;
}