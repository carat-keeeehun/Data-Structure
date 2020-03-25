#ifndef NRKFLAT_H
#define NRKFLAT_H

// unist 20131218 parkkeehun

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
	int tsize = GetTableSize();
	
	counters = new unsigned int[tsize];
	for(int i=0; i<tsize; i++)
	  counters[i] = 0;
}

NRKFlat::~NRKFlat()
{
	// Write your code
	delete [] counters;
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
	int tsize = GetTableSize();
	if(h1<0) h1=-h1;
	if(h2<0) h2=-h2;
	if(h3<0) h3=-h3;
	h1 = h1%tsize;
	h2 = h2%tsize;
	h3 = h3%tsize;
	
	bool exist = true;
	if(counters[h1]==0) exist = false;
	if(counters[h2]==0) exist = false;
	if(counters[h3]==0) exist = false;

	return exist;
}

int NRKFlat::Insert(const unsigned int key)
{
	// Write your code
	int h1, h2, h3;
	GetMMHashValue(key, h1, h2, h3);

	int tsize = GetTableSize();
	double t = tsize;
	double nok = GetNumofKeys();
	double lf = 0;

	if(h1<0) h1=-h1;
	if(h2<0) h2=-h2;
	if(h3<0) h3=-h3;
	h1 = h1%tsize;
	counters[h1]++;
	h2 = h2%tsize;
	counters[h2]++;
	h3 = h3%tsize;
	counters[h3]++;

	lf = (nok+1)/t;
	if(lf >= 0.8)
	{ // Case of resizing
	  delete [] counters;
	  counters = new unsigned int[tsize*2];
	  for(int i=0; i<tsize*2; i++)
	    counters[i] = 0;
	  return FlatHash::Insert(key);
	}
	else
	  return FlatHash::Insert(key);
}

int NRKFlat::Remove(const unsigned int key)
{
	// Write your code
	int h1, h2, h3;
	GetMMHashValue(key, h1, h2, h3);

	int tsize = GetTableSize();
	double t = tsize;

	if(h1<0) h1=-h1;
	if(h2<0) h2=-h2;
	if(h3<0) h3=-h3;
	h1 = h1%tsize;
	counters[h1]--;
	h2 = h2%tsize;
	counters[h2]--;
	h3 = h3%tsize;
	counters[h3]--;

	return FlatHash::Remove(key);
}

int NRKFlat::Search(const unsigned int key)
{
	// Write your code
	bool k = Filter(key);
	if(k==false)
	  return 0;
	else
	  return FlatHash::Search(key);
}

#endif
