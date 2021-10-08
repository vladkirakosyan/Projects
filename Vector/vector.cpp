#include <iostream>
#include "vector.h"

template<class T>
void print(Vector<T>& vec) {
	for (int i = 0; i < vec.getSize(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {

	
	Vector<int> op1{23, 44, 5, -2, 4 , 23, 64, 777};
	print(op1);
	op1.resize(4, -1);
	print(op1);
	Vector<float> op(6, 0.22);
	print(op);
	Vector<char> op3(9, 'p');
	print(op3);
	Vector<int> op4;
	op4.push_back(90);
	op4.push_back(33);
	op4.push_front(31);
	op4.push_back(22);
	op4.push_back(11);
	op4.push_front(1);
	print(op4);
	op4.erase(1);
	op4.resize(9, -1);
	print(op4);
	std::cout  << std::endl;
	std::cout << op.getCapacity() << "   " << op.getSize()<< std::endl;
	Vector<double> a;
	a.push_back(1.23);
	a.push_back(3.99);
	a.push_back(11.01);
	a.push_front(23.42);
	a.erase(0);
	print(a);

	return 0;
}
