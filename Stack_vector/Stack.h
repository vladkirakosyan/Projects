#ifndef STACK_H
#define STACK_H
#include <vector>

template <class T>
class Stack
{
public:
	explicit Stack() = default;
	// stack is allocated with the size of capacity if it belongs to 1-1000 range
	explicit Stack(int); 
	~Stack() = default;

public:
	bool isEmpty() const; 
	bool isFull() const;
	void push(T const&);
	T pop();
	T const& topOf();
	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& src)
	{
		if (src.isEmpty()) {
			return os;
		}
		for (int i = src.m_top; i >= 0; --i) {
				os << src.m_data[i] << " ";
		}
		os << "\n";
		return os;
	}
	
private:
	std::vector<T> m_data;
	int m_top{ -1 };
};



#include "stack.hpp"
#endif // STACK_H
