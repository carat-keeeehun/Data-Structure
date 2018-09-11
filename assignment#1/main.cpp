#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> LL;
	for(int i=0; i<10; i++)
		LL.AddAtHead(i);
	LL.Print(); // (9,8,7,6,5,4,3,2,1,0)
	
	cout<<LL.Get(2)<<endl; //7
	
	LL.AddAtIndex(1,8);
	LL.Print(); // (9,8,8,7,6,5,4,3,2,1,0)
	
	LL.DeleteAtIndex(3);
	LL.Print(); // (9,8,8,6,5,4,3,2,1,0)
	
	LL.DeleteValue(9);
	LL.Print(); // (8,8,6,5,4,3,2,1,0)
	
	LL.MoveToHead(2);
	LL.Print(); // (2,8,8,6,5,4,3,1,0)
	
	LL.Rotate(2);
	LL.Print(); // (1,0,2,8,8,6,5,4,3)
	
	LL.AddAtHead(4);
	LL.Print(); // (4,1,0,2,8,8,6,5,4,3)
	
	LL.Reduce();
	LL.Print(); // (4,1,0,2,8,6,5,3)
	
	LL.AddAtIndex(7,10); 
	LL.Print(); // (4,1,0,2,8,6,5,10,3)
	
	LL.Swap(); 
	LL.Print(); // (1,4,2,0,6,8,10,5,3)
	cout<<LL.Size()<<endl; // 9
	LL.CleanUp(); 
	cout<<LL.Size()<<endl; // 0
}
