#include <fstream>
#include <iostream>
#include <string>

#include "users.h"

bool Session::login(std::string temp_login, std::string temp_password) {
	if (temp_login == "") {
		user_login = "";
		user_password = "";
		permission = 0;
	}
	std::ifstream f(temp_login);
	if (!f.is_open()) return false;
	std::string password;
	f >> password;
	f.close();

	if (password == temp_password) {
		user_login = temp_login;
		user_password = temp_password;
		std::cout << "Login success!\n";
		return true;
	}

	std::cout << "Username or password are incorrect!\n";
	return false;
}

void Session::show_commands() {
	std::cout << "Commands:\n";
	if (permission >= 0) { // unsigned
		std::cout << "\tclose\n"
			<< "\tsign in\n"
			<< "\tsign out\n";
	}
	else if (permission >= 1) { // seller
		std::cout << "\tsell\n"
			<< "\tcancel\n"
			<< "\tcancel all\n"
			<< "\tconfirm\n";
	}
	else if (permission >= 2) { // head seller
		std::cout << "\tstore\n"
			<< "\tunstore\n"
			<< "\tedit\n"
			<< "\tadd discount\n"
			<< "\tremove discount\n";
	}
	else if (permission >= 3) { // administrator
		std::cout << "\tadd user\n"
			<< "\tdelete user\n";
	}
	std::cout << std::endl;
}