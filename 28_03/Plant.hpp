#pragma once

#include <memory>

#include "Harvest.hpp"

class Plant
{
public:
	Plant(const std::string& name, int height, const Harvest& harvest)
		: height_(height), name_(name), harvest_(harvest) {}

	const Harvest& takeHarvest(unsigned int quantity);

	std::string getName();
	int getHeight();
protected:
	std::string name_;
	int height_;
	Harvest harvest_;
};
