#include "storage.h"

void Storage::add_item(std::string name, unsigned int quantity)
{
	for (Item i : m) { if (i.name == name) i.quantity += quantity; break; }
}

void Storage::add_item(std::string name, unsigned int quantity, double price)
{
	m.push_back(Item(name = name, price = price, quantity = quantity));
}

void Storage::add_item(Item item) {
	for (Item i : m) {
		if (i.name == item.name) { i.quantity += item.quantity; break; }
	}
}

Item Storage::remove_item(std::string name, unsigned int quantity)
{
	for (Item i : m) {
		if (i.name == name) { return i.fetch(quantity); }
	}
}

bool Storage::valid_item(std::string name)
{
	for (Item i : m) { if (i.name == name) return true; }
	return false;
}
