#pragma once

#ifdef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <sstream>

int Divide(int a, int b);

template<typename Type>
std::string Convert(Type a) {
	std::stringstream out;
	out << a;
	return out.str();
}

#endif // !HEADER_HPP