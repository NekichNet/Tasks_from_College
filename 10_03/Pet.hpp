#include <string>

#ifndef PET_HPP
#define PET_HPP

class Pet
{
public:
	Pet(std::string name, unsigned short age = 0u) : name_(name), age_(age) {};

	std::string getName() { return name_; }
	void setName(std::string name) { name_ = name; }

	unsigned short getAge() { return age_; }
	void setAge(unsigned short age) { age_ = age; }
	void increaseAge(unsigned short increment = 1u) { age_ += increment; }
protected:
	std::string name_;
	unsigned short age_;
};

#endif // !PET_HPP