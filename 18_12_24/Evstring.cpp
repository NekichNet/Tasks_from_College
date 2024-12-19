#include "Evstring.hpp"

Evstring::Evstring(unsigned short size = DEFAULT_SIZE)
{
	char* word = new char[size];
	count++;
}

Evstring::Evstring(const char* word)
{
	size = strlen(word) + 1;
	this->word = new char[size] {0};
	memcpy(this->word, word, size);
}

Evstring::~Evstring()
{
	delete[] word;
	count--;
}

unsigned int Evstring::getSize()
{
	return size;
}

char* Evstring::getWord()
{
	return word;
}

void Evstring::print()
{
	std::cout << word;
}

void Evstring::getLine(unsigned int size = DEFAULT_SIZE, char char_to_stop = '\n') {
	this->size = size;
	word = new char[this->size];
	for (unsigned int i = 0; i < DEFAULT_SIZE; i++) {
		*(word + i) = getchar();
		if (*(word + i) == char_to_stop) { break; }
	}
}

Evstring Evstring::operator+(const Evstring& other)
{
	Evstring Temp;
	Temp.size = strlen(word) + strlen(other.word);
	Temp.word = new char[Temp.size + 1];
	memcpy(Temp.word, word, size - 1);
	memcpy(Temp.word + (size - 1), other.word, other.size);
	Temp.word[Temp.size] = '\0';
	return Temp;
}

Evstring& Evstring::operator=(const Evstring& other)
{
	size = strlen(other.word);
	word = new char[size + 1];
	memcpy(word, other.word, size);
	count++;
	return *this;
}
