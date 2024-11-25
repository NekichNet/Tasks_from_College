#pragma once

class Storage {
public:
	Storage(std::vector<Product*>& list);
	Product* get_product(unsigned int index);
	Storage add_product(Product& product, User& user);
	Storage delete_product(Product& product, User& user);
private:
	std::vector<Product*> storage;
};

class Product {
public:
	Product(std::string name, std::string password, float price, unsigned int quantity);
private:
	std::string name;
	std::string password;
	float price;
	unsigned int quantity;
};