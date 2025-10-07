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
		std::copy_n(mergeSort(m, m_length / 2), m_length / 2, left);
		std::copy_n(mergeSort(m + (m_length / 2), m_length - (m_length / 2)), m_length - (m_length / 2), right);

  		int i = 0, j = 0, k = 0;
		while (i < m_length / 2 && j < m_length - (m_length / 2)) {
			if (left[i] <= right[j]) {
				new_m[k] = left[i];
				i++;
			}
			else {
				new_m[k] = right[j];
				j++;
			}
			k++;
		}
	}
	else if (m_length == 2) {
		new_m[0] = m[0] > m[1] ? m[1] : m[0];
		new_m[1] = m[0] > m[1] ? m[0] : m[1];
	}
	else if (m_length == 1) new_m[0] = m[0];
	else throw "Array length error!";
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