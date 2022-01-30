#include <iostream>
#include "forward_list.h"

namespace constants {
	const std::initializer_list<int> num1{ 3, 4, 10, -1, 3 , 99 , 7, 13};
	const std::initializer_list<int> num2{ 4, 7, 33, -2, 54, 254, 65, 3, 9 };
	const std::initializer_list<char> charac1{ 'a', 'a', 'w', 'y', 'e', 'a', 'h'};
}

int main()
{
	const List<char> C = constants::charac1;
	std::cout << C.back() << '\n';
	std::cout << C.front() << '\n';
	std::cout << C.isEmpty() << '\n';
	std::cout << C;
	 
	List<int> A = constants::num1;
	A.push_back(77);
	A.push_back(19);
	A.pop_back();
	A.pop_back();
	
	A.insertBefore(7, -2);
	std::cout << A;

	List<int> B = constants::num2;
	B.resize(7);
	std::cout << B;
	B.resize(16, 101);
	std::cout << B;

	return 0;
}

