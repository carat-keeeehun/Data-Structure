#ifndef NRKFLAT_H
#define NRKFLAT_H

#include "FlatHash.h"
#include <iostream>
#include <stdint.h>

#define INT2VOIDP(i) (void*)(uintptr_t)(i)

class NRKFlat : public FlatHash
{
private:
	// counter array
	unsigned int* counters;

public:
	NRKFlat(enum overflow_handle _flag);

	~NRKFlat();
	
	// Hash function
	unsigned int MurmurHash2(const void* key);

	void GetMMHashValue(const unsigned int key, int& h1, int& h2, int& h3);

	bool Filter(const unsigned int key);

	// Overwriting
	int Insert(const unsigned int key);
	
	// Overwriting
	int Remove(const unsigned int key);

	// Overwriting
	int Search(const unsigned int key);
};

NRKFlat::NRKFlat(enum overflow_handle _flag) : FlatHash(_flag)
{
	// Write your code

}

NRKFlat::~NRKFlat()
{
	// Write your code

}

unsigned int NRKFlat::MurmurHash2(const void* key){
	int len = 4;
	unsigned int seed = 2018;

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	unsigned int h = seed ^ len;

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}

	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}

void NRKFlat::GetMMHashValue(const unsigned int key, int& h1, int& h2, int& h3)
{	
	// You can use h1, h2 and h3 as hashing results which you have to use to decide counter locations
	h1 = MurmurHash2(INT2VOIDP(&key));
	h2 = MurmurHash2(INT2VOIDP(&h1));
	h3 = MurmurHash2(INT2VOIDP(&h2));
}

bool NRKFlat::Filter(const unsigned int key)
{
	// You can use h1, h2 and h3 as hashing results which you have to use to decide counter locations
	int h1, h2, h3;
	GetMMHashValue(key, h1, h2, h3);

	// Write your code

	
}

int NRKFlat::Insert(const unsigned int key)
{
	// Write your code
	
}

int NRKFlat::Remove(const unsigned int key)
{
	// Write your code

}

int NRKFlat::Search(const unsigned int key)
{
	// Write your code

}

#endif
