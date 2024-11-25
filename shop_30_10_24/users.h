#pragma once

class Session {
private:
	std::string user_login = "";
	std::string user_password = "";
	std::string data;
public:
	Session();
	bool login();
	bool is_admin();
};