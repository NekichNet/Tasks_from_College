#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<string>
#include "users.h"

// Anime-Shop KawaiiDa

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Session session = Session();

	std::cout << "\t\tWelcome to \"KawaiiDa\"'s terminal\n\t\t"
		"Login into your account,\n\t\tor use \"help\" command.\n\n";

	std::string cmd;
	do {
		std::cout << "CMD >";
		std::getline(std::cin, cmd, '\n');
		if (cmd == "login") {
			session.login();
		}
	} while (cmd != "exit");

	return 0;
}