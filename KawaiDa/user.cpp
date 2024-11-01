#include "json-develop/single_include/nlohmann/json.hpp"
#include "user.h"

#include <fstream>

using json = nlohmann::json;
std::ifstream stream;

User::User(std::string username, std::string password) {
	this->username = username;
	this->password = password;
}

std::pair<bool, bool> User::is_valid() {
	stream.open("users/" + this->username + ".json");
	json data = json::parse(stream);
	stream.close();
	if (data["password"] != this->password) return std::pair<bool, bool>(false, false);
	else if (data["is_admin"] == true) return std::pair<bool, bool>(true, true);
	else return std::pair<bool, bool>(true, false);
}