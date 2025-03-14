#include <iostream>
#include <Windows.h>

#include "MyDictionary.hpp"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string text = "После этого, если у вас если осталось желание порешать побольше tasks и упражнений, рассмотрите приведенные ниже ссылки";

	MyDictionary dict("file.txt");
	
	std::multiset<std::string> result = dict.compare(text);
	
	size_t repeats = 1;
	for (std::string word : result) {
		if (repeats > 1) {
			repeats--;
			continue;
		}
		std::cout << "Слово: " << word << ", количество: " << result.count(word) << std::endl;
		if (repeats == 1 && result.count(word) > 0) {
			repeats = result.count(word);
		}
	}

	return 0;
}