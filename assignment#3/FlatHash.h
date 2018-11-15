#ifndef FLATHASH_H
#define FLATHASH_H

#include <iostream>

// Flag(hint) for overflow handling
enum overflow_handle {
	LINEAR_PROBING = 0,
	QUDRATIC_PROBING
};

class FlatHash
{
private:
	unsigned int* hashtable;
	// Variable for overflow handling
	enum overflow_handle flag;
	// Size of hash table
	unsigned int table_size;
	// Nums of keys
	unsigned int num_of_keys;

public:
	FlatHash(enum overflow_handle _flag);

	~FlatHash();

	unsigned int HashFunction(const unsigned int key) { return key % table_size; }

	unsigned int GetTableSize() { return table_size; }

	unsigned int GetNumofKeys() { return num_of_keys; }

	// Return time cost
	int Insert(const unsigned int key);

	// Remove function in lecture. Return time cost
	int Remove(const unsigned int key);

	// Return time cost
	int Search(const unsigned int key);

	void Print();
};

FlatHash::FlatHash(enum overflow_handle _flag)
{
	// Initial table size is 1000	
	table_size = 1000;
	num_of_keys = 0;
	flag = _flag;

	// Write your code


}

FlatHash::~FlatHash()
{
	// Write your code

}

int FlatHash::Insert(const unsigned int key)
{
	// You have to implement two overflow handling by using flag
	// Write your code
}

int FlatHash::Remove(const unsigned int key)
{
	// Write your code

}

int FlatHash::Search(const unsigned int key)
{
	// Write your code

}

void FlatHash::Print()
{
	// Print valid key pair - [index1:key1,index2:key2]
	// e.g., [1:3,3:7,5:1]
	std::cout << "[";

	// Write your code


	std::cout << "]" << std::endl;
}

#endif
