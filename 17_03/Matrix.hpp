#include <initializer_list>
#include <numeric>
#include <type_traits>
#include <iostream>

#ifndef MATRIX_HPP
#define MATRIX_HPP

template<typename Type, unsigned long long Coll, unsigned long long Row>
class Matrix
{
public:
	Matrix();
	Matrix(initializer_list<initializer_list<Type>> initList);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other);
	~Matrix();

	Type* operator[](unsigned long long index) const;

	unsigned long long collumns() const;
	unsigned long long rows() const;

	const Matrix& operator=(const Matrix& other);
	const Matrix& operator=(Matrix&& other);

	friend const Matrix& operator+(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator-(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator*(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^(const Matrix& lso, const Matrix& rso);

	friend const Matrix& operator+=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator-=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator*=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/=(const Matrix& lso, const Matrix& rso);

	friend std::ostream& operator<<(std::ostream& outs, const Matrix& rso);
	friend std::istream& operator>>(std::istream& ins, const Matrix& rso);
private:
	Type data_[Coll][Row];
};

namespace std {
	template<typename Type, unsigned long long Coll, unsigned long long Row>
	struct hash<Matrix<Type, Coll, Row>>
	{
		size_t operator()(Matrix<Type, Coll, Row>& obj) {
			size_t result{};
			for (size_t i = 0; i < obj.rows(); i++) {
				for (size_t j = 0; j < obj.collumns(); j++) {
					result <<= 1;
					result ^= hash<Type, Coll, Row>()(obj[i][j]);
				}
			}
			return result;
		}
	};
}

#endif // !MATRIX_HPP