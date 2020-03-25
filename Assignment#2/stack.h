#ifndef STACK_H
#define STACK_H

//
// Array-based stack data structure
//
// CSE221 Fall 2018
//
// unist 20131218 parkkeehun
#include <iostream>
#include <math.h>
#include <assert.h>

template<class type>
class Stack
{
private:
	// Data
	type *array;
	int capacity;
	int top;

public:
	// Default constructor 
	Stack(){
		capacity = 10;
		top = -1;
		array = new type[capacity];
	};

	// Destructor
	~Stack();

	// Return top element of stack
	type& Top();
	
	void Push(const type& item);
	
	void Pop();
	
	bool IsEmpty() const;

	void Print() {
		for(int i=0; i<=top; i++) std::cout << array[i] << std::endl;
	};
	
	int Size() { return top+1; }
};

#ifndef STACK_TXX
#define STACK_TXX
#include "stack.txx"
#endif

#endif
