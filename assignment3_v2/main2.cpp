#include "FlatHash.h"
#include "HierarchyHash.h"
#include "NRKFlat.h"

#include <iostream>

int main()
{
	HierarchyHash hh(LINEAR_PROBING);
	std::cout << hh.Insert(3) << std::endl;         // 1
	std::cout << hh.Insert(7) << std::endl;         // 1
	std::cout << hh.Insert(103) << std::endl;       // 1
	std::cout << hh.Insert(903) << std::endl;       // 1
	std::cout << hh.Insert(99) << std::endl;        // 1
	std::cout << hh.Insert(1099) << std::endl;      // 2
	std::cout << hh.Insert(98) << std::endl;        // 1
	std::cout << hh.Insert(1098) << std::endl;      // 4
	std::cout << hh.Search(100) << std::endl;       // 3
	hh.Print();   // 0:[3:3,7:7,98:98,99:99]
	              // 1:[100:1099,101:1098,103:103]
	              // 9:[903:903]

	std::cout << hh.Remove(1099) << std::endl;      // 2
	hh.Print();   // 0:[3:3,7:7,98:98,99:99]
	              // 1:[100:1098,103:103]
	              // 9:[903:903]

	std::cout << hh.Remove(1098) << std::endl;       // 3
	std::cout << hh.Remove(103) << std::endl;        // 1
	std::cout << hh.GetAllocatedSize() << std::endl; // 200
	hh.Print();   // 0:[3:3,7:7,98:98,99:99]
	              // 9:[903:903]

	std::cout << hh.Insert(1903) << std::endl;       // 2 
	std::cout << hh.Remove(903) << std::endl;        // 1
	for (int i = 500; i < 1300; i++)
	{
		hh.Insert(i);
	}
	std::cout << hh.GetTableSize() << std::endl;     // 2000
	std::cout << hh.GetNumofKeys() << std::endl;     // 805
	std::cout << hh.GetAllocatedSize() << std::endl; // 1000

	return 0;
}
