#include <iostream>
#include "vector.h"

int main() {
	Vector<int> op1  { 23, 44, 5, -2, 4 , 23, 64, 777};
	Vector<int> op = op1;
	std::cout << std::endl << op.getCapacity() << "  " << op.getSize();
	for (int i = 0; i < op.getSize(); ++i) {
		std::cout << op[i] << "   ";
	}
	std::cout << std::endl;
	std::cout << op.getCapacity() << "   " << op.getSize()<< std::endl;
	Vector<double> a;
	a.push_back(1.23);
	a.push_back(3.99);
	a.push_back(11.01);
	a.push_front(23.42);
	a.erase(0);
	for (int i = 0; i < a.getSize(); ++i) {
		std::cout << a[i] << "  ";
	}
	
	std::cout << a.getSize() << "   " << a[1] << "  " << a[2] << std::endl;

	Vector<double> b(a);
	Vector<double> c = b;
//	std::cout << a[0] << "  " << a[1] << std::endl;
//	std::cout << b[0] << "  " << b[1] << std::endl;
//	std::cout << c[0] << "  " << c[1] << std::endl;

	return 0;
}