#include <iostream>

unsigned short days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// https://ru.stackoverflow.com/questions/896871
bool IsLeap(unsigned int year)
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

/*
Function has no date validation,
because it won't throw any fatal errors in any case.
*/
inline unsigned long days_gone(unsigned short day, unsigned short month, unsigned int year) {
	unsigned long days_sum = day;
	for (unsigned short i = 1; i < month; i++) {
		days_sum += days_per_month[i];
		if (i == 2 && IsLeap(year)) { days_sum++; }
	}
	days_sum += year * 365 + (year / 4) - (year / 100) + (year / 400);
	return days_sum;
}

// Task 1
unsigned long days_delta(unsigned short start_day, unsigned short start_month, unsigned int start_year,
	unsigned short end_day, unsigned short end_month, int end_year) {
	return days_gone(end_day, end_month, end_year) - days_gone(start_day, start_month, start_year);
}

// Task 2
template <typename ListType>
double mean(ListType list, unsigned int size) {
	double sum = 0;
	for (unsigned int i = 0; i < size; i++) {
		sum += list[i];
	}
	return sum / size;
}

// Task 3

template <typename ListType>
unsigned int* sign_counter(ListType list, unsigned int size) {
	unsigned int counter[3] = { 0, 0, 0 };
	for (unsigned int i = 0; i < size; i++) {
		if (list[i] == 0) { counter[1]++; }
		else { counter[(list[i] + abs(list[i])) / list[i]]++; }
	}
	std::cout << "Negative: " << counter[0] << "\nZero: " << counter[1] << "\nPositive: " << counter[2];
	return counter;
}

int main() {
	// Task 1
	std::cout << "Dates' delta: " << days_delta(1, 1, 2000, 1, 1, 2025) << std::endl;
	// Task 2
	int mylist[10] = { -4, 0, -8, 4, -3, 10, 0, 4, -5, 2 };
	std::cout << "Mean: " << mean(mylist, 10) << std::endl;
	// Task 3
	sign_counter(mylist, 10);

	return 0;
}