#include "stack.h"
#include "calculator.h"
#include <iostream>

// stack & calculator test

int main()
{
	// Calculator test
	char str[] ="-10-((-2+(2+4*3))-12) + 122 * (123 + (120+888) - 300)";
	//char str[] = "10+8-(-6+5*(-8+13))+59*(1500/150)-700";
	//char str[] = "-5*(-15+(2*5-3)*(54/2))*123-30*50/1500";
	//char str[] = "122*(123+(120+888)-300)";
	//char str[] = "-10-((-2+(2+4*3))-12)";
	// The correct result is 101372
	std::cout << Eval(str) << std::endl;
		
	return 0;
}
