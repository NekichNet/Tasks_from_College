#include "MathRational.h"

MathRational::MathRational(double num) {
	_numerator = MathInt(num);
	double num_denom = num - _numerator.to_double();
	unsigned short nine_counter = 0u;
	unsigned short zero_counter = 0u;
	for (unsigned short i = 1u; i < MAX_DENOM_LENGHT; i++) {
		_denominator = MathInt(num_denom * std::pow(10, i));
		int last_num = (_denominator - ((_denominator / 10) * 10)).to_int();
		zero_counter += last_num == 0 ? 1u : 0u;
		nine_counter += std::abs(last_num) == 9 ? 1u : 0u;
		if (nine_counter >= ROUNDING_THRESHOLD) {
			_denominator /= std::pow(10, ROUNDING_THRESHOLD);
			break;
		}
		if (zero_counter >= ZERO_DENOM_THRESHOLD) {
			_denominator /= std::pow(10, ZERO_DENOM_THRESHOLD);
			break;
		}
	}
}

void MathRational::setNumerator(MathInt numerator) { _numerator = numerator; }

void MathRational::setDenominator(MathInt denominator) { _denominator = denominator; }

void MathRational::simplify() {

}

void MathRational::inverse() { std::swap(_numerator, _denominator); }

MathInt MathRational::getNumerator() const { return _numerator; }

MathInt MathRational::getDenominator() const { return _denominator; }

MathRational MathRational::getInverse() const { return MathRational(_denominator, _numerator); }

MathInt MathRational::getUnits() const { return _numerator / _denominator; }

bool MathRational::isCorrect() const { return _denominator > _numerator; }

bool MathRational::isIncorrect() const { return _denominator <= _numerator; }

bool MathRational::isPositive() const {
	return _denominator.isPositive() == _numerator.isPositive();
}

bool MathRational::isNegative() const {
	return _denominator.isPositive() != _numerator.isPositive();
}

bool MathRational::isSame(MathRational* other) const { return this == other; }

MathRational operator+(MathRational a, MathRational b)
{
	unsigned max_num = a._units >= b._units ? a._units : b._units;
	unsigned min_num = a._units + b._units - max_num;
	return a._positive == b._positive ?
		MathRational(static_cast<unsigned>(a._units + b._units), a._positive) :
		MathRational(max_num - min_num, a._positive ? a._units >= b._units : b._units >= a._units);
}

MathRational operator-(MathRational a, MathRational b)
{
	return a + b.setSign(!b._positive);
}

MathRational operator*(MathRational a, MathRational b)
{
	return MathRational(a._units * b._units, a._positive == b._positive);
}

MathRational operator/(MathRational a, MathRational b)
{
	return MathRational(a._units / b._units, a._positive == b._positive);
}

MathRational operator%(MathRational a, MathRational b)
{
	return MathRational(a._units % b._units, a._positive == b._positive);
}

bool operator==(MathRational a, MathRational b)
{
	return a._units == b._units && a._positive == b._positive;
}

bool operator>=(MathRational a, MathRational b)
{
	return a._positive && b._positive ? a._units >= b._units :
		!(a._positive || b._positive) ? a._units < b._units :
		a._positive && !b._positive;
}

bool operator<=(MathRational a, MathRational b)
{
	return a._positive && b._positive ? a._units <= b._units :
		!(a._positive || b._positive) ? a._units > b._units :
	!a._positive && b._positive;
}

bool operator>(MathRational a, MathRational b)
{
	return a._positive && b._positive ? a._units > b._units :
	!(a._positive || b._positive) ? a._units <= b._units :
		a._positive && !b._positive;
}

bool operator<(MathRational a, MathRational b)
{
	return a._positive && b._positive ? a._units < b._units :
		!(a._positive || b._positive) ? a._units >= b._units :
		!a._positive && b._positive;
}

MathRational MathRational::operator+=(MathRational other)
{
	*this = *this + other;
	return *this;
}

MathRational MathRational::operator-=(MathRational other)
{
	*this = *this - other;
	return *this;
}

MathRational MathRational::operator*=(MathRational other)
{
	*this = *this * other;
	return *this;
}

MathRational MathRational::operator/=(MathRational other)
{
	*this = *this / other;
	return *this;
}

MathRational MathRational::operator%=(MathRational other)
{
	*this = *this % other;
	return *this;
}

MathRational MathRational::operator++()
{
	*this += 1;
	return MathRational(_units, _positive);
}

MathRational MathRational::operator++(int)
{
	MathRational num = MathRational(_units, _positive);
	++*this;
	return num;
}

MathRational MathRational::operator--()
{
	*this -= 1;
	return MathRational(_units, _positive);
}

MathRational MathRational::operator--(int)
{
	MathRational num = MathRational(_units, _positive);
	--*this;
	return num;
}

std::ostream& operator<<(std::ostream& out, const MathRational& num)
{
	out << num._positive ? "" : "-";
	out << num._units;
	return out;
}