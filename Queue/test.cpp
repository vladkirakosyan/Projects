#include <iostream>
#include "Queue.h"

namespace constants
{
	std::initializer_list<char> letters{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	std::initializer_list<int> numbers{ 3, 6, 34, 1, 54, -23, 53, -22, 88, 101, 0 };
}
int main()
{
	Queue<int> intQueue(12);
	Queue<char> charQueue(8);

	for (int i : constants::numbers)
	{
		if(!intQueue.isFull())
			intQueue.enqueue(i);
	}
	std::cout << intQueue.isEmpty() << " ";

	std::cout << intQueue.dequeue() << " ";
	std::cout << intQueue.dequeue() << " ";

	for (char element : constants::letters)
	{
		if(!charQueue.isFull())
			charQueue.enqueue(element);
	}
	for (int i = 0; i < 8; ++i)
	{
		std::cout << charQueue.dequeue() << " ";
	}



	return 0;
}
