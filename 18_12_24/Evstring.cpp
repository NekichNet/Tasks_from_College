#include "Evstring.hpp"

Evstring::Evstring(unsigned short size = DEFAULT_SIZE)
{
	this->size = size;
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

char* Evstring::operator+(const Evstring& other)
{
	size += other.size + 1;
	strcat_s(word, size, other.word);
	return word;
}

void Evstring::operator=(const Evstring& other)
{

}
