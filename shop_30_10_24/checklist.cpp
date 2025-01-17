#include "checklist.h"

#include <iomanip>
#include <iostream>
#include <fstream>

void Checklist::add_item(Item item) {
	for (Item i : m) {
		if (i.name == item.name) { i.quantity += item.quantity; break; }
	}
}

Item Checklist::remove_item(std::string item_name, unsigned int quantity)
{
	for (Item i : m) {
		if (i.name == item_name) return i.fetch(quantity);
	}
}

void Checklist::remove_all(Storage* storagePtr) {
	for (Item i : m) {
		storagePtr->add_item(i.fetch());
	}
}

double Checklist::sum_up()
{
	double total = 0.0;
	std::cout << std::setw(15) << std::left << "Name" << std::setw(8) <<
		"Quantity" << std::setw(10) << "Cost" << std::setw(10) << "Discount" << std::endl;
	for (Item i : m) {
		if (i.quantity > 0) {
			double item_cost = i.cost();
			total += item_cost;
			std::cout << std::setw(15) << std::left << i.name << std::setw(8) << i.quantity
				<< std::setw(10) << std::setprecision(2) << item_cost << std::setw(10)
				<< std::setprecision(2) << item_cost - (i.price * i.quantity) << std::endl;
		}
	}
	std::cout << "Total:" << std::setw(37) << total;
	return total;
}

void Checklist::sell()
{
	std::ofstream f(std::to_string(time(NULL)) + ".txt");
	if (f.is_open()) {
		double total = 0.0;
		f << std::setw(15) << std::left << "Name" << std::setw(8) <<
			"Quantity" << std::setw(10) << "Cost" << std::setw(10) << "Discount" << std::endl;
		for (Item i : m) {
			if (i.quantity > 0) {
				double item_cost = i.cost();
				total += item_cost;
				f << std::setw(15) << std::left << i.name << std::setw(8) << i.quantity
					<< std::setw(10) << std::setprecision(2) << item_cost << std::setw(10)
					<< std::setprecision(2) << item_cost - (i.price * i.quantity) << std::endl;
			}
		}
		f << "Total:" << std::setw(37) << total;
		f.close();
		std::cout << "Checklist was saved to file.\n";
	} else {
		std::cout << "Can't open checklist file to write.\n";
	}
	m.clear();
}

bool Checklist::valid_item(std::string name)
{
	for (Item i : m) { if (i.name == name) return true; }
	return false;
}