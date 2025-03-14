#include "MyDictionary.hpp"

#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

MyDictionary::MyDictionary(std::string filename)
{
	readFromFile(filename);
}

std::multiset<std::string> MyDictionary::split(std::string text)
{
	std::multiset<std::string> result;
	std::string alphabet_str = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿAaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz`";
	std::set<char> alphabet = std::set<char>(alphabet_str.begin(), alphabet_str.end());

	std::string word = "";

	for (unsigned char i : text) {
		if (!alphabet.contains(i) && word != "") {
			std::transform(word.begin(), word.end(), word.begin(),
				[](unsigned char c) { return std::tolower(c); });
			result.insert(word);
			word = "";
		}
		else if (alphabet.contains(i)) {
			word += i;
		}
	}

	return result;
}

std::multiset<std::string> MyDictionary::compare(std::string text)
{
	std::multiset<std::string> words_in_text = split(text);

	for (std::string word : words_in_text) {
		if (contains(word)) words_in_text.erase(word);
	}

	return words_in_text;
}

bool MyDictionary::readFromFile(std::string filename)
{
	std::ifstream in(filename);

	if (in.is_open()) {
		std::string word;
		while (std::getline(in, word, '\n')) {
			if (dict_.count(word) == 0)
				dict_.insert(word);
		}
		in.close();
		return true;
	}
	else {
		return false;
	}
}

bool MyDictionary::saveToFile(std::string filename)
{
	std::ofstream out(filename);

	if (out.is_open()) {
		for (std::string word : dict_) {
			out << word;
		}
		out.close();
		return true;
	}
	else {
		return false;
	}
}

void MyDictionary::add(std::string word)
{
	dict_.insert(word);
}

void MyDictionary::remove(std::string word)
{
	dict_.erase(word);
}

bool MyDictionary::contains(std::string word)
{
	return dict_.contains(word);
}
