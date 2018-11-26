#include "FlatHash.h"
#include "HierarchyHash.h"
#include "NRKFlat.h"

#include <iostream>

int main()
{
	FlatHash fh(LINEAR_PROBING);
	std::cout << "fh, linear probing insert test"<<std::endl;
	std::cout << fh.Insert(3) << std::endl;      // 1
	std::cout << fh.Insert(7) << std::endl;      // 1
	std::cout << fh.Insert(1003) << std::endl;   // 2
	std::cout << fh.Insert(2003) << std::endl;   // 3
	std::cout << fh.Insert(2006) << std::endl;   // 1
	std::cout << fh.Insert(3006) << std::endl;   // 3
	fh.Print();   // [3:3,4:1003,5:2003,6:2006,7:7,8:3006] 
	std::cout << fh.Insert(6) << std::endl;      // 4
	std::cout << fh.Insert(3003) << std::endl;   // 8
	fh.Print();   // [3:3,4:1003,5:2003,6:2006,7:7,8:3006,9:6,10:3003]
	std::cout << fh.Insert(5003) << std::endl;   // 9
	fh.Print();   // [3:3,4:1003,5:2003,6:2006,7:7,8:3006,9:6,10:3003,11:5003]

	return 0;
}
