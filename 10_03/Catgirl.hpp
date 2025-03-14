#include "Pet.hpp"

#ifndef CATGIRL_HPP
#define CATGIRL_HPP

class Catgirl : Pet
{
public:
	Catgirl(std::string name, std::string species, bool is_wife, unsigned short age = 0u)
		: Pet(name, age), is_wife_(is_wife), species_(species) {}
private:
	bool is_wife_;
	std::string species_;
};

#endif // !CATGIRL_HPP