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
	MathInt gcd = _denominator.GCD(_numerator); _denominator /= gcd; _numerator /= gcd;
}

void MathRational::inverse() { std::swap(_numerator, _denominator); }

MathInt MathRational::getNumerator() const { return _numerator; }

MathInt MathRational::getDenominator() const { return _denominator; }

MathRational MathRational::getInversed() const { return MathRational(_denominator, _numerator); }

MathRational MathRational::getSimplified() const
{
	MathInt gcd = _denominator.GCD(_numerator);
	return MathRational(_denominator / gcd, _numerator / gcd);
}

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

MathRational operator+(MathRational a, MathRational b) {
	MathInt lcm = a._denominator.LCM(b._denominator);
	return MathRational((a._numerator * (lcm / a._denominator)) + (b._numerator * (lcm / b._denominator)), lcm);
}

MathRational operator-(MathRational a, MathRational b)
{
	MathInt lcm = a._denominator.LCM(b._denominator);
	return MathRational((a._numerator * (lcm / a._denominator)) - (b._numerator * (lcm / b._denominator)), lcm);
}

MathRational operator*(MathRational a, MathRational b)
{
	return MathRational(a._numerator * b._numerator, a._denominator * b._denominator);
}

MathRational operator*(MathRational a, MathInt b)
{
	return MathRational(a._numerator * b, a._denominator * b);
}

MathRational operator/(MathRational a, MathRational b)
{
	return a * b.getInversed();
}

bool operator==(MathRational a, MathRational b)
{
	MathRational x = a.getSimplified(), y = b.getSimplified();
	return x._numerator == y._numerator && x._denominator == y._denominator;
}

bool operator>=(MathRational a, MathRational b)
{
	MathInt lcm = a._denominator.LCM(b._denominator);
	return (a * (lcm / a._denominator)) >= (b * (lcm / b._denominator));
}

bool operator<=(MathRational a, MathRational b)
{
	MathInt lcm = a._denominator.LCM(b._denominator);
	return (a * (lcm / a._denominator)) <= (b * (lcm / b._denominator));
}

bool operator>(MathRational a, MathRational b)
{
	MathInt lcm = a._denominator.LCM(b._denominator);
	return (a * (lcm / a._denominator)) > (b * (lcm / b._denominator));
}

bool operator<(MathRational a, MathRational b)
{
	MathInt lcm = a._denominator.LCM(b._denominator);
	return (a * (lcm / a._denominator)) < (b * (lcm / b._denominator));
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

MathRational MathRational::operator++()
{
	*this += 1;
	return *this;
}

MathRational MathRational::operator++(int)
{
	MathRational num = MathRational(_numerator, _denominator);
	++*this;
	return num;
}

MathRational MathRational::operator--()
{
	*this -= 1;
	return *this;
}

MathRational MathRational::operator--(int)
{
	MathRational num = MathRational(_numerator, _denominator);
	--*this;
	return num;
}

std::ostream& operator<<(std::ostream& out, const MathRational& num)
{
	out << num._numerator;
	out << '/';
	out << num._denominator;
	return out;
}