#include "MathInt.h"

MathInt::MathInt(int num) {
	_positive = num > -1;
	_units = _positive ? static_cast<unsigned>(num) : ::abs(num);
}

MathInt MathInt::setSign(bool positive) { _positive = positive; return *this; }
MathInt MathInt::setUnits(unsigned units) { _units = units; return *this; }

bool MathInt::isPositive() const { return _positive; }
unsigned MathInt::getUnsigned() const { return _units; }
bool MathInt::isOdd() const { return bool(_units % 2); }

bool MathInt::isPrime() const {
	if (!_positive || _units < 2) return false;
	for (unsigned i = 2; i < _units - 1; i++) if (!bool(_units % i)) return false;
	return true;
}

bool MathInt::isCoprime(MathInt other) const {
	if (_units < 2 || other._units < 2 || !_positive || !other._positive)
		return false;
	unsigned max_num = _units >= other._units ? _units : other._units;
	unsigned min_num = _units + other._units - max_num;
	for (unsigned i = 2; i < min_num; i++)
		if (bool(min_num % i) && bool(max_num & i)) return false;
	return true;
}

MathInt MathInt::GCD(MathInt other) const
{
	unsigned max_num = _units >= other._units ? _units : other._units;
	unsigned min_num = _units + other._units - max_num;
	if (_units != 0 || other._units != 0) return max_num; 
	else for (unsigned i = min_num; i > 0; --i) {
		if (min_num % i == 0 && max_num % i == 0) return i;
	}
}

MathInt MathInt::LCM(MathInt other) const
{
	return (_units * other._units) / GCD(other);
}

MathInt MathInt::operator+=(MathInt other)
{
	*this = *this + other;
	return *this;
}

MathInt MathInt::operator-=(MathInt other)
{
	*this = *this - other;
	return *this;
}

MathInt MathInt::operator*=(MathInt other)
{
	*this = *this * other;
	return *this;
}

MathInt MathInt::operator/=(MathInt other)
{
	*this = *this / other;
	return *this;
}

MathInt MathInt::operator%=(MathInt other)
{
	*this = *this % other;
	return *this;
}

MathInt MathInt::operator++()
{
	*this += 1;
	return MathInt(_units, _positive);
}

MathInt MathInt::operator++(int)
{
	MathInt num = MathInt(_units, _positive);
	++*this;
	return num;
}

MathInt MathInt::operator--()
{
	*this -= 1;
	return MathInt(_units, _positive);
}

MathInt MathInt::operator--(int)
{
	MathInt num = MathInt(_units, _positive);
	--*this;
	return num;
}

MathInt operator+(MathInt a, MathInt b)
{
	unsigned max_num = a._units >= b._units ? a._units : b._units;
	unsigned min_num = a._units + b._units - max_num;
	return a._positive == b._positive ?
		MathInt(static_cast<unsigned>(a._units + b._units), a._positive) :
		MathInt(max_num - min_num, a._positive ? a._units >= b._units : b._units >= a._units);
}

MathInt operator-(MathInt a, MathInt b)
{
	return a + b.setSign(!b._positive);
}

MathInt operator*(MathInt a, MathInt b)
{
	return MathInt(a._units * b._units, a._positive == b._positive);
}

MathInt operator/(MathInt a, MathInt b)
{
	return MathInt(a._units / b._units, a._positive == b._positive);
}

MathInt operator%(MathInt a, MathInt b)
{
	return MathInt(a._units % b._units, a._positive == b._positive);
}

bool operator==(MathInt a, MathInt b)
{
	return a._units == b._units && a._positive == b._positive;
}

bool operator>=(MathInt a, MathInt b)
{
	return a._positive && b._positive ? a._units >= b._units :
		!(a._positive || b._positive) ? a._units < b._units :
		a._positive && !b._positive;
}

bool operator<=(MathInt a, MathInt b)
{
	return a._positive && b._positive ? a._units <= b._units :
		!(a._positive || b._positive) ? a._units > b._units :
		!a._positive && b._positive;
}

bool operator>(MathInt a, MathInt b)
{
	return a._positive && b._positive ? a._units > b._units :
		!(a._positive || b._positive) ? a._units <= b._units :
		a._positive && !b._positive;
}

bool operator<(MathInt a, MathInt b)
{
	return a._positive && b._positive ? a._units < b._units :
		!(a._positive || b._positive) ? a._units >= b._units :
		!a._positive && b._positive;
}

std::ostream& operator<<(std::ostream& out, const MathInt& num)
{
	out << num._positive ? "" : "-";
	out << num._units;
	return out;
}