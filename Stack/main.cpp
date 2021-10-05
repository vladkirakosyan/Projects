#include <iostream>
#include "stack.h"

int main(){
	
	Stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	std::cout << "size_is_ " << a.size() << std::endl;
	std::cout << a.pop() << " ";
	std::cout << a.pop() << " ";
	std::cout << a.top() << " ";
	a.push(23);
	
	return 0;
}