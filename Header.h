#pragma once
#include <iostream>

class Integer {
private:
	int value;
public:
	Integer(); //Constructor
	Integer(int v); //Parameterized Constructor
	~Integer(); //Destructor
	Integer(const Integer& other); //Copy Constructor
	Integer& operator=(const Integer& other); //Copy Assignment Operator
	Integer(Integer&& other); //Move Constructor
	Integer& operator=(Integer&& other); //Move Assignment Operator
	Integer operator+(const Integer& other) const; //Addition Operator
	Integer operator-(const Integer& other) const; //Subtraction Operator
	Integer operator++(); //Prefix Increment Operator
	Integer operator++(int); //Postfix Increment Operator
};