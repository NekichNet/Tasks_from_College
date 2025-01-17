#pragma once

#include<string>

struct Item {
	std::string name;
	double price;
	unsigned int quantity;
	std::string discount_type = "";
	double discount_modifier = 0.0;

	Item(std::string name, double price, unsigned int quantity,
		std::string discount_type = "", double discount_modifier = 0.0);
	inline double cost();
	Item fetch();
	Item fetch(unsigned int quantity_to_fetch);
};