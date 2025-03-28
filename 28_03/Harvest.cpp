#include "Harvest.hpp"

const Harvest& Harvest::takeHarvest(unsigned int quantity)
{
    if (quantity_ >= quantity) {
        quantity_ -= quantity;
        return *(new Harvest(name_, weight_, quantity));
    } else {
        quantity = quantity_;
        quantity_ = 0u;
        return *(new Harvest(name_, weight_, quantity_));
    }
}

std::string Harvest::getName()
{
    return name_;
}

unsigned int Harvest::getWeight()
{
    return weight_;
}

unsigned int Harvest::getQuantity()
{
    return quantity_;
}
