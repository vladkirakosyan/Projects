#include "Queue.h"

template<class T>
Queue<T>::Queue(int cap)
	: m_cap{ cap }, m_length{}
{
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return m_length == 0;
}

template<class T>
bool Queue<T>::isFull() const
{
	return m_length == m_cap;
}

template<class T>
T Queue<T>::headOf() const
{
	return *m_data.begin();
}

template<class T>
T Queue<T>::dequeue()
{
	if (isEmpty()) {
		std::cout << "Program terminated queue is empty.\n";
		throw - 1;
	}
	T ret = *m_data.begin();
	m_data.pop_front();
	--m_length;
	return ret;
}

template<class T>
void Queue<T>::enqueue(const T& val)
{
	if (isFull()) {
		std::cout << "Program terminated queue is full.\n";
		throw - 1;
	}
	else {
		m_data.push_back(val);
		++m_length;
	}
}
