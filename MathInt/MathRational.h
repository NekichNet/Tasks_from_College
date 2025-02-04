#pragma once

#include "MathInt.h"

const unsigned short MAX_DENOM_LENGHT = 9u;
const unsigned short ZERO_DENOM_THRESHOLD = 5u;
const unsigned short ROUNDING_THRESHOLD = 5u;

class MathRational {
public:
	MathRational() : MathRational(MathInt(0u), MathInt(1u)) {};
	MathRational(MathInt numerator, MathInt denominator = MathInt(1u)) : _numerator(numerator), _denominator(denominator) {};
	MathRational(int numerator, int denominator = 1u) : _numerator(numerator), _denominator(denominator) {};
	MathRational(double num);
	MathRational(std::string numerator, std::string denominator) : _numerator(numerator), _denominator(denominator) {};
private:
	MathInt _numerator;
	MathInt _denominator;
};