#include "Pet.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : Pet
{
public:
	Dog(std::string name, std::string species, bool is_male, unsigned short age = 0u)
		: Pet(name, age), is_male_(is_male), species_(species) {}
private:
	bool is_male_;
	std::string species_;
};

#endif // !DOG_HPP