#ifndef STRING_HPP
#define STRING_HPP

#include<iostream>
#include<string>

class Evstring
{
public:
	Evstring();
	explicit Evstring(int length);
	Evstring(const char* str);

	~Evstring();
	Evstring(const Evstring& other);
	Evstring& operator=(const Evstring& other);

	Evstring(Evstring&& other) noexcept;
	Evstring& operator=(Evstring&& other);

	void reserve(int new_len);
	void shrink_to_fit();
	void clean();
	bool empty() const;

	int capacity() const;
	int size() const;

	Evstring& operator+=(const Evstring& other);
	Evstring& operator+=(char ch);
	friend Evstring& operator+(const Evstring& lsd, const Evstring& rsd);
	friend Evstring& operator+(const Evstring& lsd, char ch);
	friend Evstring& operator+(char ch, const Evstring& rsd);

	friend bool operator<(const Evstring& lsd, const Evstring& rsd);
	friend bool operator>(const Evstring& lsd, const Evstring& rsd);
	friend bool operator<=(const Evstring& lsd, const Evstring& rsd);
	friend bool operator>=(const Evstring& lsd, const Evstring& rsd);
	friend bool operator==(const Evstring& lsd, const Evstring& rsd);
	friend bool operator!=(const Evstring& lsd, const Evstring& rsd);

	char& operator[](long long i) noexcept;
	const char& operator[](long long i) const noexcept;

	char& at(long long i);
	const char& at(long long i) const;

	friend std::ostream& operator<<(std::ostream out, const Evstring& str);
	friend std::istream& operator>>(std::istream in, const Evstring& str);

	char* data();
	const char* c_str() const;

	class iterator{};
	class const_iterator{};
	class right_iterator{};
	class const_right_iterator{};

	iterator begin();
	iterator end();

	right_iterator rbegin();
	right_iterator rend();

	const_iterator cend() const;
	const_iterator cbegin() const;

	const_right_iterator crbegin() const;
	const_right_iterator crend() const;

	void insert(iterator& obj, char ch);
	void emplace(iterator& obj, char ch);

	void insert(right_iterator& obj, char ch);
	void emplace(right_iterator& obj, char ch);

	void push_back(char ch);
	void emplace_back(char ch);
public:
	struct {}allocator_;
	char* str_;
	size_t size_;
	size_t capacity_;
};

#endif // !STRING_HPP