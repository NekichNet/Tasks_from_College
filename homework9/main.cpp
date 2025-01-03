#include <iostream>
#include <cstdlib>
#include "task2.hpp"

template <typename ListType>
ListType sum_list(ListType* start_pointer, unsigned short size) {
	ListType sum{};
	for (ListType* i = start_pointer; i != start_pointer + size; i++) { sum += *i; }
	return sum;
}

// Task 1
template <typename ListType>
unsigned short find_min_sum(ListType* list, unsigned short list_size,
	unsigned short min_sum_size, unsigned short offset = 0, unsigned short min_pos = 0) {
	if (offset >= list_size - min_sum_size) { return min_pos; }
	ListType sum = sum_list(list + offset, min_sum_size);
	if (sum < sum_list(list + min_pos, min_sum_size)) { min_pos = offset; }
	return find_min_sum(list, list_size, min_sum_size,
		offset=offset + 1, min_pos=min_pos);
}

int main() {
	srand(time(NULL));

	// Task 1
	unsigned const short m_size = 100, min_sum_range = 10;
	short m[m_size];

	std::cout << "List: [ ";
	for (unsigned short i = 0; i < m_size; i++)
	{ m[i] = rand() % 10; std::cout << m[i] << ' '; }
	std::cout << ']' << std::endl;

	unsigned short pos = find_min_sum(m, m_size, min_sum_range);
	std::cout << "Position: " << pos << "\nValues: [ ";
	for (unsigned short i = pos; i < pos + min_sum_range; i++) { std::cout << m[i] << ' '; }
	std::cout << ']' << std::endl;

	// Task 2
	short m1[10] = { 1, 534, 78, 2, 44, 675, 5, 8, 3, 5 },
		m2[3][3] = { {4, 3, 6}, {3, 7, 12}, {5, 2, 6} },
		m3[2][2][2] = { {{5, 3}, {7, 2}}, {{34, 4}, {56, 4}} };
	int a = 454364, b = 653578, c = 935346;

	std::cout << maxValue(m1, 10u) << '\n'
		<< maxValue(m2, 3u) << '\n'
		<< maxValue(m3, 2u) << '\n'
		<< maxValue(a, b) << '\n'
		<< maxValue(a, b, c) << '\n';

	return 0;
}