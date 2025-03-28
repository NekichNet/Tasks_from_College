#pragma once

#include "Harvest.hpp"

class Berry : Harvest
{
public:
	Berry(const std::string& name, unsigned int weight, unsigned int quantity, bool hasPit)
		: Harvest(name, weight, quantity), hasPit_(hasPit) {}
protected:
	bool hasPit_;
};
