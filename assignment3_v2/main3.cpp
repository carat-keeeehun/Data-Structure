nclude "FlatHash.h"
#include "HierarchyHash.h"
#include "NRKFlat.h"

#include <iostream>

int main()
{
	NRKFlat nh(QUDRATIC_PROBING);
	std::cout << nh.Insert(3) << std::endl;      // 1
	std::cout << nh.Insert(7) << std::endl;      // 1
	std::cout << nh.Insert(1003) << std::endl;   // 2
	std::cout << nh.Insert(2003) << std::endl;   // 4
	std::cout << nh.Insert(2006) << std::endl;   // 1
	std::cout << nh.Insert(3006) << std::endl;   // 3
	nh.Print();   // [3:3,4:1003,6:2006,7:7,10:3006,12:2003]

	// True Negative
	std::cout << nh.Search(1) << std::endl;   // 0
	
	// Insert for False Positive Example
	std::cout << nh.Insert(155) << std::endl; // 1
	std::cout << nh.Insert(13) << std::endl; // 1
	std::cout << nh.Insert(111) << std::endl; // 1

	// False Positive
	std::cout << nh.Search(1) << std::endl;   // 1
	// True Positive
	std::cout << nh.Search(2003) << std::endl;   // 4
	
	std::cout << nh.Remove(7) << std::endl;      // 1
	nh.Print();   // [3:3,4:1003,6:2006,10:3006,12:2003,13:13,111:111,155:155]
	
	nh.ClearTombstones();
	nh.Print();   // [3:3,4:1003,6:2006,7:3006,12:2003,13:13,111:111,155:155]
	
	return 0;
}
