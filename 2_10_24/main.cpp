#include <iostream>
#include <Windows.h>
#include <cstdlib>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	unsigned const short size = 10;

	// FIRST TASK

	short m[size];
	for (short i = 0; i < size; i++) {
		m[i] = rand() % 10 - 5;
	}
	short min = m[0], max = m[0];
	for (short i = 0; i < size; i++) {
		if (min > m[i]) min = m[i];
		if (max < m[i]) max = m[i];
	}
	std::cout << "Max: " << max << "\nMin: " << min << "\n\n";

	// SECOND TASK

	int range0, range1, cap;
	std::cout << "Enter min of the range: ";
	std::cin >> range0;
	std::cout << "Enter max of the range: ";
	std::cin >> range1;
	std::cout << "Enter numbers' max cap: ";
	std::cin >> cap;

	int list[size];
	int sum = 0;
	for (short j = 0; j < size; j++) {
		list[j] = rand() % (range1 - range0) + range0;
		if (list[j] < cap) sum += list[j];
	}
	std::cout << "Sum: " << sum << "\n\n";
	
	// THIRD TASK

	int income[12];
	std::string months[]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (short l = 0; l < 12; l++) {
		std::cout << "Enter the income in " << months[l] << ": ";
		std::cin >> income[l];
	}
	unsigned short month_start, month_end;
	std::cout << "Enter start month: ";
	std::cin >> month_start;
	std::cout << "Enter end month: ";
	std::cin >> month_end;

	int min_income = income[month_start], max_income = income[month_start];
	for (; month_start < month_end; month_start++) {
		if (min_income > income[month_start]) min_income = income[month_start];
		if (max_income < income[month_start]) max_income = income[month_start];
	}
	std::cout << "Min income is: " << min_income << "\nMax income is: " << max_income << "\n\n";

	return 0;
}