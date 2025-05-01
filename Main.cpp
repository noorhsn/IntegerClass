#include "Header.h"
#include <iostream>
#include <memory>

//Smart Pointers:
void ProcessUniquePtr(std::unique_ptr<Integer> & ptr) {
	std::cout << "Processing unique pointer" << std::endl;
}
void ProcessSharedPtr(std::shared_ptr<Integer> ptr) {
	std::cout << "Processing shared pointer" << std::endl;
	std::cout << "ProcessSharedPtr::Shared pointer count: " << ptr.use_count() << std::endl;
}

//1: Unique Pointer
//Unique pointers are used to manage the lifetime of an object, 
// ensuring that only one unique pointer can own the object at a time. 
// They cannot be copied, but they can be moved.
void CreateUniqueInteger() {
	std::unique_ptr <Integer> ptr(new Integer);
	std::cout << "Unique pointer created" << std::endl;
	//auto newPtr(ptr); // This line will cause a compilation error because unique_ptr cannot be copied
	auto newPtr = std::move(ptr); // Move the unique_ptr
	//ProcessUniquePtr(ptr); // This will cause a runtime error because ptr is now nullptr
	ProcessUniquePtr(newPtr); // Pass the unique_ptr to the function
}
//2: Shared Pointer
//Shared pointers are used to manage the lifetime of an object, 
// allowing multiple shared pointers to own the same object. 
// They keep track of the number of references to the object 
// and automatically delete it when there are no more references.
void CreateSharedInteger() {
	std::shared_ptr<Integer> ptr(new Integer);
	std::cout << "Shared pointer created" << std::endl;
	std::cout << "CreateSharedInteger 1::Shared pointer reference count: " << ptr.use_count() << std::endl; // Check the reference count
	ProcessSharedPtr(ptr); // Pass the shared_ptr to the function
	auto newPtr(ptr); // This will not cause a compilation error because shared_ptr can be copied
	auto newPtr2 = std::move(ptr); // Move the shared_ptr
	//ProcessSharedPtr(ptr); // This will cause a runtime error because ptr is now nullptr
	ProcessSharedPtr(newPtr2); // Pass the moved shared_ptr to the function
	std::cout << "CreateSharedInteger 2::Shared pointer reference count: " << newPtr.use_count() << std::endl; // Check the reference count
}
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
	CreateUniqueInteger();
	CreateSharedInteger();
	return 0;
}