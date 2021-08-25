#include <initializer_list>
#ifndef vector
#define vector

template <class T>
class Vector {
public:
	Vector();   // default constructor
	~Vector();  // destructor
	Vector(std::initializer_list<T> a);
	Vector<T>(const Vector<T>& other);            // copy constructor
	Vector<T>& operator=(const Vector<T>& other); // operator=
	Vector(Vector<T>&& rhs);		       		  // move constructor
	Vector<T>& operator=(Vector<T>&& rhs);        // move assignment operator
	Vector<T> operator+(const Vector<T>& rhs);    // operator+


public:
	void push_back(const T& element);
	void push_front(const T& element);
	T& operator[](int iter);
	void erase(int size_pos);
	int getCapacity() const;
	int getSize() const;

private:
	int m_size;
	int m_cap;
	T* m_arr;
};


#include "vec_.hpp"
#endif // vector