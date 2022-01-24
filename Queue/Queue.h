#ifndef QUEUE_H
#define QUEUE_H
#include <list>

template <class T>
class Queue
{
public: 
	explicit Queue(int cap = 10);

public: 
	T dequeue();				// deletes and return first inserted element
	void enqueue(const T& val); // adds element
	T headOf() const;			// returns first inserted element
	bool isEmpty() const;		
	bool isFull() const;
		
private:
	std::list<T> m_data;
	int m_length;
	const int m_cap;
};

#include "queue.hpp"
#endif // QUEUE_H

