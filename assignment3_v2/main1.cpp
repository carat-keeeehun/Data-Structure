#include "FlatHash.h"
#include "HierarchyHash.h"
#include "NRKFlat.h"

#include <iostream>

int main()
{
	FlatHash fh1(QUDRATIC_PROBING);
	std::cout << fh1.Insert(1008) << std::endl;     // 1
	std::cout << fh1.Insert(8009) << std::endl;     // 1
	std::cout << fh1.Insert(2001) << std::endl;     // 1
	std::cout << fh1.Insert(5008) << std::endl;     // 3
	std::cout << fh1.Insert(6008) << std::endl;     // 4
	std::cout << fh1.Insert(4009) << std::endl;     // 2
	std::cout << fh1.Insert(9) << std::endl;        // 3
	fh1.Print();    // [1:2001,8:1008,9:8009,10:4009,12:5008,13:9,17:6008]

	FlatHash fh2(QUDRATIC_PROBING);
	int a = 1;
	for(int i = 0; i < 157; i++){
		fh2.Insert(a);
		a+=1000;
	}
	std::cout << fh2.Insert(a+=1000) << std::endl;  // 247
	std::cout << fh2.Insert(a+=1000) << std::endl;  // 249
	std::cout << fh2.Insert(a+=1000) << std::endl;  // 1003
	std::cout << fh2.Insert(a+=1000) << std::endl;  // 1004

	return 0;
}
