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
		if (nine_counter >= ROUNDING_THRESHOLD) { _denominator /= std::pow(10, 5); break; }
	}
	// TODO: Strip zeros.
}
