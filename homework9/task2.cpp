#include "task2.hpp"

template <typename ListType>
ListType maxValue(ListType list[], unsigned int size) {
	ListType value = list[0];
	for (unsigned int i = 1; i < size; i++) { if (list[i] > value) value = list[i]; }
	return value;
}

template <typename ListType>
ListType maxValue(ListType list[][3], unsigned int size) {
	ListType value = list[0][0];
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (list[i][j] > value) value = list[i][j];
		}
	}
	return value;
}

template <typename ListType>
ListType maxValue(ListType list[][2][2], unsigned int size) {
	ListType value = list[0][0][0];
	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < 2; j++) {
			for (unsigned int l = 0; l < 2; l++) {
				if (list[i][j][l] > value) value = list[i][j][l];
			}
		}
	}
	return value;
}

int maxValue(int a, int b) { if (a > b) { return a; } return b; }

int maxValue(int a, int b, int c) {
	int value;
	if (a > b) { value = a; }
	else { value = b; }
	if (value > c) { return value; }
	return c;
}