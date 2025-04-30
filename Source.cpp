#include "Header.h"

Integer::Integer() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Integer::Integer(int v) : value(v) {
	std::cout << "Parameterized constructor called with value: " << v << std::endl;
}
Integer::~Integer() {
	std::cout << "Destructor called for value: " << value << std::endl;
}
Integer::Integer(const Integer& other) : value(other.value) {
	std::cout << "Copy constructor called for value: " << value << std::endl;
}
Integer& Integer::operator=(const Integer& other) {
	if (this != &other) {
		value = other.value;
		std::cout << "Copy assignment operator called for value: " << value << std::endl;
	}
	return *this;
}
Integer::Integer(Integer&& other) : value(other.value) {
	other.value = 0; // Reset the moved-from object
	std::cout << "Move constructor called for value: " << value << std::endl;
}
Integer& Integer::operator=(Integer&& other) {
	if (this != &other) {
		value = other.value;
		other.value = 0; // Reset the moved-from object
		std::cout << "Move assignment operator called for value: " << value << std::endl;
	}
	return *this;
}
Integer Integer::operator+(const Integer& other) const {
	std::cout << "Addition operator called" << std::endl;
	return Integer(value + other.value);
}
Integer Integer::operator-(const Integer& other) const {
	std::cout << "Subtraction operator called" << std::endl;
	return Integer(value - other.value);
}
Integer Integer::operator++() {
	value++; // Increment the current object
	std::cout << "Prefix increment operator called, new value: " << value << std::endl;
	return *this; // Return the current state
}
Integer Integer::operator++(int) {
	Integer temp = *this; // Store the current state
	value++; // Increment the current object
	std::cout << "Postfix increment operator called, new value: " << value << std::endl;
	return temp; // Return the old state
}