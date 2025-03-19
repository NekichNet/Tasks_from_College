#pragma once

#include <set>
#include <string>

class MyDictionary
{
public:
	MyDictionary(std::string filename);
	MyDictionary(std::set<std::string> dict) : dict_(dict) {}

	std::multiset<std::string> split(std::string text);
	std::multiset<std::string> compare(std::string text);

	bool readFromFile(std::string filename);
	bool saveToFile(std::string filename);

	void add(std::string word);
	void remove(std::string word);
	bool contains(std::string word);
private:
	std::set<std::string> dict_;
};