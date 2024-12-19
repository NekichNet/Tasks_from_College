#pragma once

#ifndef _EVSTRING_HPP_
#define _EVSTRING_HPP_
#include <iostream>
#include <string>

class Evstring
{
public:
	static const unsigned short DEFAULT_SIZE = 52;

	Evstring(unsigned short size = DEFAULT_SIZE) { this->size = size; };
	Evstring(const char* word);
	~Evstring();

	unsigned int getSize();
	char* getWord();

	void print();

	void getLine(char char_to_stop) { char_to_stop = '\n'; };

	Evstring operator+(const Evstring& other);
	Evstring& operator=(const Evstring& other);
private:
	char* word;
	unsigned int size;
	unsigned int count = 0;
};

#endif // !_EVTRING_HPP_