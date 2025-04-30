#include "Header.h"
#include <iostream>

int main() {
	Integer x; // Calls the default constructor
	Integer a(5); // Calls the parameterized constructor
	Integer b(10); // Calls the parameterized constructor
	Integer c = a; // Calls the copy constructor
	c = a; // Calls the copy assignment operator
	Integer d = std::move(a); // Calls the move constructor
	d = std::move(b); // Calls the move assignment operator
	Integer e = d + c; // Calls the addition operator
	Integer f = d - c; // Calls the subtraction operator
	Integer g = d++; // Calls the postfix increment operator
	Integer h = ++c; // Calls the prefix increment operator
	return 0;
}