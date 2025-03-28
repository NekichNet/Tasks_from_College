#include "Plant.hpp"

const Harvest& Plant::takeHarvest(unsigned int quantity)
{
	return harvest_.takeHarvest(quantity);
}
