#include <iostream>
#include <string>
#include "forward_list.h"
#include <list>

template<typename T>
void print(List<T>& A){
	std::cout << "Values are: ";
	for (int i = 0; i < A.GetSize(); ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}
List<int> foo() 
{
  List<int> k;
  k.push_front(12);
  k.push_front(177);
  return k;
}

int main() {
	List <int> qq{ 43, 54, 22, 2 };

	
	List<double> aa(5, 1.01);
	std::cout << "aa size " << aa.GetSize() << std::endl;
	print(aa);
	aa.pop_back();
	print(aa);
	
	List<int>a;
	List<double> q;
	q.push_back(23.3);
	q.push_back(5.5);
	q.push_back(77.44);
	std::cout << q.GetSize() << std::endl;
	print(q);
	a.push_back(5);
	a.push_back(12);
	a.push_front(91);
	a.push_front(3);
//	a.pop_back();
//	a.pop_front();
	print(a);
	a.removeAt(2);
	print(a);
	List<int> k;
	k = foo();
	std::cout << "k is "; 
	print(k);
	
	return 0;
}