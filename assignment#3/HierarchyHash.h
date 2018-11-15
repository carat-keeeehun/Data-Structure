#ifndef HIERARCHYHASH_H
#define HIERARCHYHASH_H

#include <iostream>
#include "FlatHash.h"

class HierarchyHash
{
private:
	unsigned int** hashtable;
	// Variable for overflow handling
	enum overflow_handle flag;
	// Size(range) of full hash table. Initially 1000
	unsigned int table_size;
	// Size of subhash table. Fixed by 100
	unsigned int sub_table_size;
	// Nums of keys
	unsigned int num_of_keys;

public:
	HierarchyHash(enum overflow_handle _flag);

	~HierarchyHash();

	unsigned int HashFunction(const int key) { return key % table_size; }

	unsigned int GetTableSize() { return table_size; }

	unsigned int GetNumofKeys() { return num_of_keys; }

	// Return the size of allocated sub hash table
	unsigned int GetAllocatedSize();

	// Return time cost
	int Insert(const unsigned int key);

	// Return time cost
	int Remove(const unsigned int key);

	// Return time cost
	int Search(const unsigned int key);

	void Print();
};

HierarchyHash::HierarchyHash(enum overflow_handle _flag)
{
	// Initial map size is 1000
	table_size = 1000;
	// Table size is fixed to 100
	sub_table_size = 100;
	flag = _flag;

	// Write your code


}

HierarchyHash::~HierarchyHash()
{
	// Write your code

}

unsigned int HierarchyHash::GetAllocatedSize()
{
	// Write your code

}

int HierarchyHash::Insert(const unsigned int key)
{
	// Write your code

}

int HierarchyHash::Remove(const unsigned int key)
{
	// Write your code

}

int HierarchyHash::Search(const unsigned int key)
{
	// Write your code

}

void HierarchyHash::Print()
{
	// Print valid key pair for each sub hash table - subtable_id:[index1:key1,index2:key2]
	// Seperate each sub table by endl
	// e.g., 0:[1:3,3:7,5:1]
	//       1:[101:2,192:10]
	//       9:[902:90,938:82]

	// Write your code


}

#endif
