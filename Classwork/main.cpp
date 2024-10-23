#include<iostream>
#include<Windows.h>
#include<string>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const std::string LOGIN = "Admin";
	const std::string VERYMAXSECURITYpassword = "SOMAXSECURITY";

	std::string input_login, input_password;

	std::cout << "Enter login: ";
	std::getline(std::cin, input_login, '\n');
	std::cout << "Enter password: ";
	std::getline(std::cin, input_password, '\n');

	if (input_login.length() > 15 || input_password.length() > 15)
	{ std::cout << "Login / password length can't be more then 15!\n"; }
	else if (input_login == LOGIN && input_password == VERYMAXSECURITYpassword)
	{ std::cout << "Authorized succesfully."; }
	else { std::cout << "Login / password is incorrect!"; }
}