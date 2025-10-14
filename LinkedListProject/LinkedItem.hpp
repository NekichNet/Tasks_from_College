#pragma once

template<typename Type>
class LinkedItem
{
	LinkedItem();
	LinkedItem(initializer_list<initializer_list<Type>> initList);
	LinkedItem(const LinkedItem& other);
	LinkedItem(LinkedItem&& other);
	~LinkedItem();

	Type* operator[](unsigned long long index) const;

	const LinkedItem& operator=(const LinkedItem& other);
	const LinkedItem& operator=(LinkedItem&& other);
};
