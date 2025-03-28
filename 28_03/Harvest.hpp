#pragma once

#include <string>

class Harvest
{
public:
	Harvest(const std::string& name, unsigned int weight, unsigned int quantity)
		: name_(name), weight_(weight), quantity_(quantity) {}

	const Harvest& takeHarvest(unsigned int quantity);

	std::string getName();
	unsigned int getWeight();
	unsigned int getQuantity();
protected:
	std::string name_;
	unsigned int weight_;
	unsigned int quantity_;
};
