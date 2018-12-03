#include "FlatHash.h"
#include "HierarchyHash.h"
#include "NRKFlat.h"

#include <iostream>

int main()
{
	FlatHash fh(LINEAR_PROBING);
std::cout << fh.Insert(1) << std::endl;
std::cout << fh.Insert(1001) << std::endl;
std::cout << fh.Insert(999) << std::endl;
std::cout << fh.Insert(1999) << std::endl;
std::cout << fh.Insert(2999) << std::endl;
fh.Print();
std::cout << fh.Search(2999) << std::endl;
std::cout << fh.Remove(1999) << std::endl;
fh.Print();
std::cout << fh.Search(2999) << std::endl;

	std::cout << "fh, linear probing insert test"<<std::endl;
	std::cout << fh.Insert(3) << std::endl;      // 1
	std::cout << fh.Insert(7) << std::endl;      // 1
	std::cout << fh.Insert(1003) << std::endl;   // 2
	std::cout << fh.Insert(2003) << std::endl;   // 3
	std::cout << fh.Insert(2006) << std::endl;   // 1
	std::cout << fh.Insert(3006) << std::endl;   // 3
	fh.Print();   // [3:3,4:1003,5:2003,6:2006,7:7,8:3006]

	std::cout << fh.Remove(2003) << std::endl;
	fh.Print();
	std::cout << fh.Insert(2003) << std::endl;
	fh.Print();
	std::cout << fh.Insert(1004) << std::endl;
	std::cout << fh.Insert(2004) << std::endl;
	std::cout << fh.Insert(3003) << std::endl;
	fh.Print();
	std::cout << fh.Remove(3) << std::endl;
	fh.Print();

	for(int i = 100; i<900; i++)
		fh.Insert(i);

	std::cout << fh.GetTableSize() << std::endl;
	std::cout << fh.GetNumofKeys() << std::endl;

	for(int i = 150; i<850; i++)
		fh.Remove(i);

	std::cout << fh.GetTableSize() << std::endl;
	std::cout << fh.GetNumofKeys() << std::endl;
	fh.Print();
/*
	std::cout << fh.Insert(6) << std::endl;      // 4
	std::cout << fh.Insert(3003) << std::endl;   // 8
	fh.Print();   // [3:3,4:1003,5:2003,6:2006,7:7,8:3006,9:6,10:3003]
	std::cout << fh.Insert(5003) << std::endl;   // 9
	fh.Print();   // [3:3,4:1003,5:2003,6:2006,7:7,8:3006,9:6,10:3003,11:5003]
*/
	return 0;
}
