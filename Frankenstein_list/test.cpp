#include <iostream>
#include "frankenstein_list.h"

int main()
{
	selfOrganizingList::Flist<int> a;
	//a.push_back(12);
	a.push_front(3);
	//a.push_back(5);
	a.push_front(2);
	a.push_back(9);
	std::cout << a.front() << ' ';
	std::cout << a.back() << ' ';
	std::cout << "Size is " << a.size() << '\n';


	selfOrganizingList::Flist<float> b;
	b.push_front(-4.2);
	b.push_front(3.3);
	b.push_back(-9.f);
	b.push_back(4.5);
	
	std::cout << "max is " << b.maxElem() << '\t';
	std::cout << "min is " << b.minElem() << '\t';
	std::cout << "size is " << b.size() << '\n';
	
	b.insert(2, 32.f);
	b.printSortedWay(true);
	std::cout << std::endl;
	b.printSortedWay(false);


	return 0;
}
