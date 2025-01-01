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

int main() {


	return 0;
}