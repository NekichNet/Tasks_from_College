#pragma once

class User {
public:
	User(std::string username, std::string password);
	std::pair<bool, bool> is_valid();
private:
	std::string username;
	std::string password;
};