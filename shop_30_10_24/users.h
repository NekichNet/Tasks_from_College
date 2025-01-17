#pragma once

class Session {
private:
	std::string user_login = "";
	std::string user_password = "";
	unsigned short permission = 0;
public:
	bool login(std::string temp_login, std::string temp_password);
	void show_commands();
};