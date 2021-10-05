#include "Stack.h"

template<class T>
inline Stack<T>::Stack(int size)
{
	m_cap = (size > 0 && size < 1000) ? size : 10;
	m_top = -1;
	m_arr = new T [m_cap];
}

template<class T>
void Stack<T>::push(const T& elem) 
{
	if (!isFull()) {
		m_arr[++m_top] = elem;
	}
	else {
		std::cout << "Program terminated, stack is full." << std::endl;
		exit(0);
	}
	
}

template<typename T>
T Stack<T>::pop() noexcept
{
	if (!isEmpty()) {
		return m_arr[m_top--];
	}
	else {
		std::cout << "Program terminated, stack is empty." << std::endl;
		exit(0);
	}
}


template<class T>
inline const int Stack<T>::top() const{
	if (!isEmpty()) {
		return m_arr[m_top];
	} 
	return -1;
}
