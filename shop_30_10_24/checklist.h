#pragma once

#include <vector>

#include "item.h"
#include "storage.h"

class Checklist
{
private:
	static std::vector<Item> m;
public:
	void add_item(Item item);
	Item remove_item(std::string item_name, unsigned int quantity);
	void remove_all(Storage* storagePtr);
	double sum_up();
	void sell();
	bool valid_item(std::string name);
};