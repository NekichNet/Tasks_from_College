#include "Pet.hpp"

#ifndef PARROT_HPP
#define PARROT_HPP

class Parrot : Pet
{
public:
	Parrot(std::string name, std::string species, std::string color, bool is_male, unsigned short age = 0u)
		: Pet(name, age), is_male_(is_male), color_(color), species_(species) {}
private:
	bool is_male_;
	std::string species_, color_;
};

#endif // !PARROT_HPP

