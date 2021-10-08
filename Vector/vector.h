#include <initializer_list>
#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
public:
	Vector();   // default constructor
	~Vector();  // destructor
	Vector(int counter, const T& elem);           // ctor with parameters
	Vector(std::initializer_list<T> a);           // initializer_list
	Vector<T>(const Vector<T>& other);            // copy constructor
	Vector<T>& operator=(const Vector<T>& other); // operator=
	Vector<T>(Vector<T>&& rhs) noexcept;		  // move constructor
	Vector<T>& operator=(Vector<T>&& rhs);        // move assignment operator
	Vector<T> operator+(const Vector<T>& rhs);    // operator+

public:
	void push_back(const T& element);
	void push_front(const T& element);

	T& operator[](const int iter) const;
	T& at(const int iter) const;
	
	void erase(int size_pos);
	void resize(int s,const T& elem);

	int getCapacity() const;
	int getSize() const;

private:
	int m_size;
	int m_cap;
	T* m_arr;
};


#include "vec_.hpp"
#endif // VECTOR_H