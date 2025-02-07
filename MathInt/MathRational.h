#pragma once

#include "MathInt.h"

class MathRational {
public:
	MathRational() : MathRational(MathInt(0u), MathInt(1u)) {};
	MathRational(MathInt numerator, MathInt denominator = MathInt(1u)) : _numerator(numerator), _denominator(denominator) {};
	MathRational(int numerator, int denominator = 1u) : _numerator(numerator), _denominator(denominator) {};
	MathRational(double num);
	MathRational(std::string numerator, std::string denominator) : _numerator(numerator), _denominator(denominator) {};

	void setNumerator(MathInt numerator);
	void setDenominator(MathInt denominator);
	void simplify();
	void inverse();

	MathInt getNumerator() const;
	MathInt getDenominator() const;
	MathRational getInversed() const;
	MathRational getSimplified() const;
	MathInt getUnits() const;
	bool isCorrect() const;
	bool isIncorrect() const;
	bool isPositive() const;
	bool isNegative() const;
	bool isSame(MathRational* other) const;

	MathRational operator=(int num) { return MathRational(num); }
	MathRational operator=(unsigned num) { return MathRational(num, true); }

	friend MathRational operator+(MathRational a, MathRational b);
	friend MathRational operator-(MathRational a, MathRational b);
	friend MathRational operator*(MathRational a, MathRational b);
	friend MathRational operator*(MathRational a, MathInt b);
	friend MathRational operator/(MathRational a, MathRational b);

	friend bool operator==(MathRational a, MathRational b);
	friend bool operator>=(MathRational a, MathRational b);
	friend bool operator<=(MathRational a, MathRational b);
	friend bool operator>(MathRational a, MathRational b);
	friend bool operator<(MathRational a, MathRational b);

	MathRational operator+=(MathRational other);
	MathRational operator-=(MathRational other);
	MathRational operator*=(MathRational other);
	MathRational operator/=(MathRational other);

	MathRational operator++();
	MathRational operator++(int);
	MathRational operator--();
	MathRational operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const MathRational& num);

	static unsigned short MAX_DENOM_LENGHT;
	static unsigned short ZERO_DENOM_THRESHOLD;
	static unsigned short ROUNDING_THRESHOLD;
private:
	MathInt _numerator;
	MathInt _denominator;
};

unsigned short MathRational::MAX_DENOM_LENGHT = 9u;
unsigned short MathRational::ZERO_DENOM_THRESHOLD = 5u;
unsigned short MathRational::ROUNDING_THRESHOLD = 5u;