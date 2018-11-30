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

	// Delete tombstomes
	void ClearTombstones();

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
	hashtable = new unsigned int*[table_size/sub_table_size];
	for(int i=0; i<10; i++)
	  hashtable[i] = NULL;

	if(flag != LINEAR_PROBING && flag != QUDRATIC_PROBING)
	{
	  std::cout << "Input LINEAR_PROBING or QUDRATIC_PROBING" << std::endl;
	  return;
	}
}

HierarchyHash::~HierarchyHash()
{
	// Write your code
	for(int i=0; i<table_size/sub_table_size; i++)
	  delete [] hashtable[i];
	delete [] hashtable;
}

unsigned int HierarchyHash::GetAllocatedSize()
{
	// Write your code

}

int HierarchyHash::Insert(const unsigned int key)
{
	// Write your code
	int idx;
	int index;
	int time_cost = 0;
	double l_factor;
	int q_fail = 0;

	if(flag == QUDRATIC_PROBING)
	{
	  for(int j=0; j<table_size; j++)
	  {
	    idx = (key + j*j)%table_size;
	    index = (key + j*j)%sub_table_size;

	    if(hashtable[idx/100] == NULL){
	      hashtable[idx/100] = new unsigned int[sub_table_size];
	      for(int i=0; i<sub_table_size; i++)
		hashtable[idx/100][i] = 0;}

	    if(hashtable[idx/100][index]==0||hashtable[idx/100][index]==T){
	      time_cost++;
	      hashtable[idx/100][index] = key;
	      num_of_keys++;
	      return time_cost;}

	    if(j==table_size-1) q_fail=1;

	    time_cost++;
	  }
	}
	if(flag == LINEAR_PROBING || q_fail == 1)
	{
	  for(int j=0; j>table_size; j++)
	  {
	    idx = (key + j)%table_size;
	    index = (key + j)%sub_table_size;

	    if(hashtable[idx/100] == NULL){
	      hashtable[idx/100] = new unsigned int[sub_table_size];
	      for(int i=0; i<sub_table_size; i++)
		hashtable[idx/100][i] = 0;}

	    if(hashtable[idx/100][index]==0){
	      time_cost++;
	      hashtable[idx/100][index] = key;
	      num_of_keys++;

	      l_factor = num_of_keys/table_size;
	      if(l_factor >= 0.8)
	      {
		std::cout << "******Resizing******" << std::endl;
		unsigned int **temp = new unsigned int*[2*table_size/sub_table_size];
		for(int i=0; i<2*table_size/sub_table_size; i++){
		  temp[i] = new unsigned int[sub_table_size];
		  if(hashtable[i]!=NULL){
		    for(int k=0; k<sub_table_size; k++)
		      temp[i][k] = hashtable[i][k];}}
		unsigned int **hashtable = new unsigned int*[2*table_size/sub_table_size];
		for(int i=0; i<2*table_size/sub_table_size; i++){
		  hashtable[i] = new unsigned int[sub_table_size];
		  if(temp[i]!=NULL){
		    for(int k=0; k<sub_table_size; k++)
		      hashtable[i][k] = temp[i][k];}}
		table_size = table_size*2;
		for(int i=0; i<table_size/sub_table_size; i++)
		  delete [] temp[i];
		delete [] temp;
	      }}
	    return time_cost;
	  }
	}
}

int HierarchyHash::Remove(const unsigned int key)
{
	// Write your code

}

int HierarchyHash::Search(const unsigned int key)
{
	// Write your code

}

void HierarchyHash::ClearTombstones()
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
