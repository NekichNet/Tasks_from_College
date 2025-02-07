#pragma once

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class MathInt {
public:
	MathInt() :MathInt(0u) {}
	MathInt(unsigned units, bool positive = true) :_units(units), _positive(positive) {}
	MathInt(int num);
	MathInt(double num) :MathInt(static_cast<int>(num)) {};
	MathInt(std::string num) :MathInt(std::stoi(num)) {};

	MathInt setSign(bool positive);
	MathInt setUnits(unsigned units);

	bool isPositive() const;
	bool isNegative() const;
	unsigned getUnsigned() const;
	bool isOdd() const;
	bool isEven() const;
	bool isPrime() const;

	bool isSame(MathInt* other) const;
	
	// Calculates only in unsigned values!
	bool isCoprime(MathInt other) const;

	MathInt GCD(MathInt other) const;
	MathInt LCM(MathInt other) const;

	MathInt operator=(int num) { return MathInt(num); }
	MathInt operator=(unsigned num) { return MathInt(num, true); }

	friend MathInt operator+(MathInt a, MathInt b);
	friend MathInt operator-(MathInt a, MathInt b);
	friend MathInt operator*(MathInt a, MathInt b);
	friend MathInt operator/(MathInt a, MathInt b);
	friend MathInt operator%(MathInt a, MathInt b);

	friend bool operator==(MathInt a, MathInt b);
	friend bool operator>=(MathInt a, MathInt b);
	friend bool operator<=(MathInt a, MathInt b);
	friend bool operator>(MathInt a, MathInt b);
	friend bool operator<(MathInt a, MathInt b);
	
	MathInt operator+=(MathInt other);
	MathInt operator-=(MathInt other);
	MathInt operator*=(MathInt other);
	MathInt operator/=(MathInt other);
	MathInt operator%=(MathInt other);

	MathInt operator++();
	MathInt operator++(int);
	MathInt operator--();
	MathInt operator-();
	MathInt operator--(int);
	
	friend std::ostream& operator<<(std::ostream& out, const MathInt& num);
	friend std::istream& operator>>(std::istream& in, const MathInt& num);

	int to_int() const;
	double to_double() const;
	bool to_bool() const;

	std::vector<MathInt> getDividers() const;
	std::vector<MathInt> getPrimeDividers() const;
private:
	bool _positive;
	unsigned _units;
};