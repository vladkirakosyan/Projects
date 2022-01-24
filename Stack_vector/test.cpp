#include <iostream>
#include "Stack.h"

namespace constants
{
	std::initializer_list<char> letters{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	std::initializer_list<int> numbers{ 3, 6, 34, 1, 54, -23, 53, -22, 88, 101, 0};
}
int main()
{
	Stack<int> intStack(10);
	for (int i : constants::numbers)
	{
		intStack.push(i);
	}
	std::cout << intStack;
	std::cout << "isFull() " << intStack.isFull() << "\n";
	std::cout << "isEmpty() " << intStack.isEmpty() << "\n\n";



	Stack<char> charStack;
	for (char element : constants::letters)
	{
		charStack.push(element);
	}
	std::cout << charStack;
	std::cout << "pop last element " << charStack.pop();
	std::cout << " next is " << charStack.pop() << '\n';

	std::cout << charStack;
	std::cout << "isFull() " << charStack.isFull() << "\n";
	std::cout << "isEmpty() " << charStack.isEmpty() << "\n";
	

	return 0;
}
