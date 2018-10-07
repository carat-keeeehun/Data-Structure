#include "stack.h"
#include "calculator.h"
#include <iostream>

// stack & calculator test

int main()
{
	// Calculator test
	char str[] ="-10-((-2+(2+4*3))-12) + 122 * (123 + (120+888) - 300)";
	
	// The correct result is 101372
	std::cout << Eval(str);
		
	return 0;
}
