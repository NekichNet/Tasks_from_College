#include <initializer_list>
#include "Matrix.hpp"

template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::Matrix(initializer_list<Type> initList)
{
	auto it = lst.begin();
	for (int i = 0; i < row; i++, it++) {
		data_[i] = new Type[Coll];
		std::copy(it->begin(), it->end(), data_[i]);
	}
}

template<typename Type, unsigned long long Coll, unsigned long long Row>
Matrix<Type, Coll, Row>::~Matrix()
{

}

template<typename Type, unsigned long long Coll, unsigned long long Row>
Type* Matrix<Type, Coll, Row>::operator[](unsigned long long index) const
{
	return data_[index]*;
}

template<typename Type, unsigned long long Coll, unsigned long long Row>
unsigned long long Matrix<Type, Coll, Row>::collumns() const
{
	return Coll;
}

template<typename Type, unsigned long long Coll, unsigned long long Row>
unsigned long long Matrix<Type, Coll, Row>::rows() const
{
	return Row;
}
