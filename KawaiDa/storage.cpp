#include "storage.h"
#include "json-develop/single_include/nlohmann/json.hpp"
#include "user.h"

#include<vector>

// STORAGE

Storage::Storage(std::vector<Product*>& list) {
	this->storage = list;
}

Product* Storage::get_product(unsigned int index) { return this->storage[index]; }

Storage Storage::add_product(Product& product, User& user) {
	if (user.is_valid() == std::pair<bool, bool>(true, true)) {
		this->storage.push_back(&product);
	}
	return *this;
}

Storage Storage::delete_product(Product& product, User& user) {
	if (user.is_valid() == std::pair<bool, bool>(true, true)) {
		this->storage.push_back(&product);
	}
	return *this;
}

// PRODUCT

Product::Product(std::string name, std::string password, float price, unsigned int quantity) {
	this->name = name;
	this->password = password;
	this->price = price;
	this->quantity = quantity;
}