#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {

public:
	Stack(int size = 10);
	~Stack() { delete[] m_arr; }
	void push(const T&);
	T pop() noexcept;
	const int top() const;
	int size() const { return m_top + 1; }
	bool isEmpty() const { return m_top == -1; }
	bool isFull() const { return m_top == m_cap - 1; }

private:
	int m_cap;
	int m_top;
	T* m_arr;
};

#include "stack.cpp" 
#endif // STACK_H