#ifndef FLATHASH_H
#define FLATHASH_H

#include <iostream>

// Flag(hint) for overflow handling
enum overflow_handle {
	LINEAR_PROBING = 0,
	QUDRATIC_PROBING
};

// Tombstone
enum {T = 1000001};

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

	// Delete tombstones
	void ClearTombstones();

	void Print();
};

FlatHash::FlatHash(enum overflow_handle _flag)
{
	// Initial table size is 1000	
	table_size = 1000;
	num_of_keys = 0;
	flag = _flag;

	// Write your code
	hashtable = new unsigned int[table_size];
	for(int i=0; i<table_size; i++)
	  hashtable[i] = 0;

	if(flag != LINEAR_PROBING && flag != QUDRATIC_PROBING)
	{
	  std::cout << "Input LINEAR_PROBING or QUDRATIC_PROBING" << std::endl;
	  return;
	}
}

FlatHash::~FlatHash()
{
	// Write your code
	delete [] hashtable;
}

int FlatHash::Insert(const unsigned int key)
{
	// You have to implement two overflow handling by using flag
	// Write your code
	for(int i=0; i<table_size; i++)
	{
	  if(hashtable[i]==key){
	    std::cout << "Already exist key" << std::endl;
	    return 0;}
	}
	
	int index;
	int time_cost = 0;
	double l_factor, n, t;
	int q_fail = 0;
	if(flag == QUDRATIC_PROBING)
	{
	  for(int j=0; j<table_size; j++)
	  {
	    index = (key + j*j)%table_size;
	    if(hashtable[index]==0||hashtable[index]==T){
	      time_cost++;
	      hashtable[index] = key;
	      num_of_keys++;
	      return time_cost;}

	    if(j==table_size-1) q_fail=1; //Fail in QUDRATIC_PROBING

	    time_cost++;
	  }
	}
	if(flag == LINEAR_PROBING || q_fail == 1)
	{
	  for(int j=0; j<table_size; j++)
	  {
	    index = (key + j)%table_size;
	    if(hashtable[index]==0){
	      time_cost++;
	      hashtable[index] = key;
	      num_of_keys++;

	      n = num_of_keys;
	      t = table_size;
	      l_factor = n/t;

	      if(l_factor >= 0.8)
	      {
		std::cout << "*****Resizing*****" << std::endl;
		unsigned int *temp = new unsigned int[table_size];
		for(int i=0; i<table_size; i++)
		  temp[i] = hashtable[i];
		table_size = table_size*2;
		delete [] hashtable;

		hashtable = new unsigned int[table_size];
		for(int i=0; i<table_size; i++)
		{
		  if(i < (table_size/2))
		    hashtable[i] = temp[i];
		  else
		    hashtable[i] = 0;
		}
		delete [] temp;
	      }
	      return time_cost;}
	    time_cost++;
	  }
	}
}

int FlatHash::Remove(const unsigned int key)
{
	// Write your code
	int time_cost = 0;
	int index;
	int k;
	if(flag == QUDRATIC_PROBING)
	{
	  for(int j=0; j<table_size; j++)
	  {
	    index = (key + j*j)%table_size;
	    if(hashtable[index]==key){
	      time_cost++;
	      hashtable[index] = T;
	      num_of_keys--;
	      return time_cost;}

	    time_cost++;
	    if(hashtable[index]==0){
	      std::cout << "No value to be removed" << std::endl;
	      return time_cost;}
	  }
	}

	if(flag == LINEAR_PROBING)
	{ 
	  for(int j=0; j<table_size; j++)
	  {
	    index = (key + j)%table_size;
	    if(hashtable[index]==key){
	      time_cost++;
	      num_of_keys--;

	      // removing and shifting
	      for(int i=index+1; i<=index+table_size; i++)
	      {
		hashtable[index] = 0;
		if(hashtable[i]!=0){
		  if(hashtable[i]%table_size > index){
		    if(hashtable[i]%table_size > i){
		      hashtable[index] = hashtable[i];
		      hashtable[i] = 0;
		      index = i%table_size;}}
		  if(hashtable[i]%table_size <= index){
		    hashtable[index] = hashtable[i];
		    hashtable[i] = 0;
		    index = i%table_size;}}
		else break;
	      }
	      return time_cost;}

	    if(j == table_size-1){
	      std::cout << "No value to be removed" << std::endl;
	      return ++time_cost;}
	    time_cost++;
	  }
	}
}

int FlatHash::Search(const unsigned int key)
{
	// Write your code
	int time_cost = 0;
	int index;

	if(flag == QUDRATIC_PROBING)
	{
	  for(int j=0; j<table_size; j++)
	  {
	    index = (key + j*j)%table_size;
	    if(hashtable[index]==key){
	      time_cost++;
	      return time_cost;}

	    time_cost++;
	    if(hashtable[index]==0){
	      std::cout << "Fail to search" << std::endl;
	      return time_cost;}
	  }
	}

	if(flag == LINEAR_PROBING)
	{
	  for(int j=0; j<table_size; j++)
	  {
	    index = (key + j)%table_size;
	    if(hashtable[index]==key){
	      time_cost++;
	      return time_cost;}

	    time_cost++;
	    if(hashtable[index]==0){
	      std::cout << "Fail to search" << std::endl;
	      return time_cost;}
	  }
	}
}

void FlatHash::ClearTombstones()
{
	// Write your code
	for(int i=0; i<table_size; i++){
	  if(hashtable[i]==T) hashtable[i]=0;}
}

void FlatHash::Print()
{
	// Print valid key pair - [index1:key1,index2:key2]
	// e.g., [1:3,3:7,5:1]
	std::cout << "[";

	// Write your code
	int comma = 0;
	for(int i=0; i<table_size; i++)
	{
	  if(hashtable[i]!=0)
	  {
	    if(comma==1)
	      std::cout << "," << i << ":" << hashtable[i];
	    if(comma==0){
	      std::cout << i << ":" << hashtable[i];
	      comma = 1;}
	  }
	}

	std::cout << "]" << std::endl;
}

#endif
