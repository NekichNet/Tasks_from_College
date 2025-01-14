#include<iostream>
#include<Windows.h>
#include<string>

#include "users.h"
#include "item.h"
#include "checklist.h"
#include "storage.h"

// Anime-Shop KawaiiDa

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Session session = Session();
	Storage storage = Storage();
	Checklist check = Checklist();

	std::cout << "\t\tWelcome to \"KawaiiDa\"'s terminal\n"
		"\t\tLogin into your account.\n\n";

	std::string cmd;
	do { // Main cycle
		system("cls");
		std::cout << "Items to sell:\n";
		check.sum_up();
		session.show_commands();
		std::cout << "CMD >";
		std::getline(std::cin, cmd, '\n');

		// Permission 0 - unsigned
		if (cmd == "sign in") {
			std::string temp_login;
			std::string temp_password;
			std::cout << "Enter login: ";
			std::getline(std::cin, temp_login, '\n');
			std::cout << "Enter password: ";
			std::getline(std::cin, temp_password, '\n');
			std::cout << temp_login.empty() << " " << temp_password << " " << "\n";
			session.login(temp_login, temp_password);
		}
		else if (cmd == "sign out") { session.login("", ""); }

		// Permission 1 - seller
		else if (cmd == "sell") {
			// TODO: сделать отображение склада
			std::string temp_item_name;
			unsigned int temp_item_quantity;
			std::cout << "Enter item name: ";
			std::getline(std::cin, temp_item_name, '\n');
			if (storage.valid_item(temp_item_name)) {
				std::cout << "Enter quantity: ";
				std::cin >> temp_item_quantity;
				check.add_item(storage.remove_item(temp_item_name, temp_item_quantity));
			}
			else {
				std::cout << "Invalid item name.\n";
			}
		}
		else if (cmd == "cancel") {
			std::string temp_item_name;
			std::cout << "Enter item name: ";
			std::getline(std::cin, temp_item_name, '\n');
			if (check.valid_item(temp_item_name)) {
				unsigned int temp_item_quantity;
				std::cout << "Enter quantity: ";
				std::cin >> temp_item_quantity;
				storage.add_item(check.remove_item(temp_item_name, temp_item_quantity));
			}
			else {
				std::cout << "Item not found.\n";
			}
		}
		else if (cmd == "cancel all") { check.remove_all(&storage); }
		else if (cmd == "confirm") { check.sell(); }

		// Permission 2 - head seller
		else if (cmd == "store") {
			std::string temp_item_name;
			unsigned int temp_item_quantity;
			std::cout << "Enter item name: ";
			std::getline(std::cin, temp_item_name, '\n');
			std::cout << "Enter quantity: ";
			std::cin >> temp_item_quantity;
			if (storage.valid_item(temp_item_name)) {
				storage.add_item(temp_item_name, temp_item_quantity);
			}
			else {
				double temp_item_price;
				std::cout << "Enter price: ";
				std::cin >> temp_item_price;
				storage.add_item(temp_item_name, temp_item_quantity, temp_item_price);
			}
		}
		else if (cmd == "unstore") {}
		else if (cmd == "edit") {}
		else if (cmd == "add discount") {}
		else if (cmd == "remove discount") {}
		
		// Permission 3 - administrator
		else if (cmd == "add user") {}
		else if (cmd == "delete user") {}

	} while (cmd != "close");

	return 0;
}