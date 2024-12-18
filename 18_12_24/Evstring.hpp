#pragma once

#ifndef _EVSTRING_HPP_
#define _EVSTRING_HPP_
#include <iostream>
#include <string>

class Evstring
{
public:
	static const unsigned short DEFAULT_SIZE = 52;

	Evstring(unsigned short size);
	Evstring(const char* word);
	~Evstring();

	unsigned int getSize();
	char* getWord();

	char* operator+(const Evstring& other);
	void operator=(const Evstring& other);
private:
	char* word;
	unsigned int size;
	unsigned int count = 0;
};

#endif // !_EVTRING_HPP_