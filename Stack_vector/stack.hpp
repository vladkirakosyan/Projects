//#include "Stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack(int cap)
{
	int m_cap = (cap > 0 && cap < 1000) ? cap : 10;
	m_data.reserve(m_cap);
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return m_top == -1;
}

template <typename T>
bool Stack<T>::isFull() const
{
	return m_top == m_data.capacity();
}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty()) {
		std::cout << "Program terminated, stack is empty.\n";
		throw - 1;
	}
	else {
		--m_top;
		T tmp = m_data[m_data.size() - 1];
		m_data.pop_back();
		return tmp;
	}
}

template<typename T>
inline void Stack<T>::push(T const& val)
{
	if (isFull()) {
		std::cout << "Program terminated, stack is full.\n";
		throw - 1;
	}
	else {
		++m_top;
		m_data.push_back(val);
	}
}

template<typename T>
T const& Stack<T>::topOf()
{
	if (!isEmpty()) {
		return m_data[m_top];
	}
	else {
		return -1;
	}
}
