#include <fstream>
#include <iostream>
#include <string>

#include "users.h"

Session::Session() {
	std::ifstream f("users.json");
	json data = json::parse(f);
	f.close();
}

bool Session::login() {
	std::string temp_login;
	std::string temp_password;

	std::cout << "Enter login: ";
	std::getline(std::cin, temp_login, '\n');
	std::cout << "Enter password: ";
	std::getline(std::cin, temp_password, '\n');

	std::cout << temp_login.empty() << " " << temp_password << " " << "\n";

	if (data.contains(temp_login)) {
		if (data[temp_login][0] == temp_password) {
			user_login = temp_login;
			user_password = temp_password;
			std::cout << "Login success!\n";
			return true;
		}
	}
	std::cout << "Username or password are incorrect!\n";
	return false;
}

bool Session::is_admin() {
	return data[user_login];
}