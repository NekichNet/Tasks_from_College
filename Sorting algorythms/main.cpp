#include <iostream>
#include <algorithm>
#include <ctime>

void printList(int m[], unsigned m_length) {
	for (unsigned i = 0u; i < m_length - 1; i++) std::cout << m[i] << ", ";
	std::cout << m[m_length - 1] << std::endl;
}

int* mergeSort(int m[], unsigned m_length) {
	int* new_m{new int[m_length]};
	if (m_length > 2) {
		int* left{ new int[m_length / 2] };
		int* right{ new int[m_length - (m_length / 2)] };
		std::copy_n(m, m_length / 2, left);
		std::copy_n(m + (m_length / 2), m_length / 2, right);
		std::copy_n(mergeSort(left, m_length / 2), m_length / 2, new_m);
		std::copy_n(mergeSort(right, m_length - (m_length / 2)), m_length - (m_length / 2), new_m + (m_length / 2));
	}
	else if (m_length == 2) {
		new_m[0] = m[0] > m[1] ? m[1] : m[0];
		new_m[1] = m[0] > m[1] ? m[0] : m[1];
	}
	else if (m_length == 1) new_m[0] = m[0];
	else throw "List length error!";
	return new_m;
}

int main() {
	srand(time(0));

	const unsigned int SIZE = 8u;

	int start_m[SIZE];
	for (unsigned i = 0u; i < SIZE; i++) { start_m[i] = std::rand() % 101; }
	printList(start_m, SIZE);

	std::cout << std::endl;

	int* new_m{ mergeSort(start_m, SIZE) };
	printList(new_m, SIZE);

	return 0;
}