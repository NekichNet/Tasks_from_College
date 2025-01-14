#pragma once

#include <vector>

#include "item.h"

class Storage
{
private:
	static std::vector<Item> m;
public:
	void add_item(std::string name, unsigned int quantity);
	void add_item(std::string name, unsigned int quantity, double price);
	void add_item(Item item);
	Item remove_item(std::string name, unsigned int quantity);
	bool valid_item(std::string name);
};