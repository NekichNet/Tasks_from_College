#pragma once

#include <cmath>

class MathInt {
public:
	MathInt() :MathInt(0u) {}
	MathInt(unsigned units, bool positive = true) :_units(units), _positive(positive) {}
	MathInt(int num) { _positive = num > -1;
	_units = _positive ? static_cast<unsigned>(num) : ::abs(num); }

	void setSign(bool positive) { _positive = positive; }
	void setUnits(unsigned units) { _units = units; }

	bool isPositive() const { return _positive; }
	unsigned getUnsigned() const { return _units; }
	bool isOdd() const { return bool(_units % 2); }
	bool isPrime() const { 
		if (!_positive || _units < 2) return false;
		for (unsigned i = 2; i < _units - 1; i++) if (!bool(_units % i)) return false;
		return true;
	}
	
	// Calculates only in abs()'ed values!
	bool isCoprime(MathInt other) const {
		unsigned max_num = _units >= other._units ? _units : other._units;
		unsigned min_num = _units + other._units - max_num;
		if (_units < 2 || other._units < 2 || !_positive || !other._positive)
			return false;
		for (unsigned i = 2; i < min_num; i++)
			if (bool(min_num % i) && bool(max_num & i)) return false;
		return true;
	}

	// TODO: Add NOK and NOD

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
private:
	bool _positive;
	unsigned _units;
};