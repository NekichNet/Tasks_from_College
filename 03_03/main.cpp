#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <type_traits>
#include <scoped_allocator>

template<typename Type>
void Print(Type var) {
	std::cout << var << std::endl;
}

template<typename Type, typename ...Args>
void Print(Type var, const Args&... args) {
	std::cout << var;
	Print(args...);
}

int main() {
	std::vector<int, std::allocator<int>> vect;

	std::array<int, 5> arr;

	std::tuple<int, bool, float> tup{ true, 124, 54.f };

	Print("5326", 54.f, "gre", 432);
}