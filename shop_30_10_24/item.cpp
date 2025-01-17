#include "item.h"

Item::Item(std::string name, double price, unsigned int quantity,
	std::string discount_type, double discount_modifier) {
	this->name = name;
	this->price = std::abs(price);
	this->quantity = quantity;
	this->discount_type = discount_type;
	this->discount_modifier = discount_modifier;
}

inline double Item::cost() {
	double sum = price * quantity;
	if (discount_type == "simple") {
		sum -= sum * discount_modifier;
	}
	else if (discount_type == "each n free") {
		sum -= (unsigned int)(quantity / discount_modifier) * price;
	}
	return sum;
}

Item Item::fetch() {
	unsigned int temp_quantity = quantity;
	quantity = 0;
	return Item(name, price, temp_quantity,
		discount_type, discount_modifier);
}

Item Item::fetch(unsigned int quantity_to_fetch) {
	if (quantity_to_fetch > quantity) quantity_to_fetch = quantity;
	quantity -= quantity_to_fetch;
	return Item(name, price, quantity_to_fetch,
		discount_type, discount_modifier);
}