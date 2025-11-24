#include <iostream>
#include "MemorizedFib.hpp"

int main() {
	int value = MemorizedFib::find(10);
	std::cout << value << std::endl;
	return 0;
}