#include <iostream>
#include "frankenstein_list.h"

int main()
{
	selfOrganizingList::Flist<int> a;
	a.push_back(12);
	a.push_front(3);
	//a.push_back(5);
	a.push_front(2);
	a.push_back(9);
	std::cout << a.front() << ' ';
	std::cout << a.back() << ' ';
	std::cout << a.size() << '\n';




	return 0;
}
