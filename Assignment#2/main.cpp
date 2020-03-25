#include "stack.h"
#include "calculator.h"
#include <iostream>

// stack & calculator test

int main()
{
	// Calculator test
	// Input expression into str[]
	char str[] ="";
	
	//char str[] = "10+8-(-6+5*(-8+13))+59*(1500/150)-700";
	// Answer : -111

	//char str[] = "-5*(-15+(2*5-3)*(54/2))*123-30*50/1500";
	// Answer : -107011	

	//char str[] = "122*(123+(120+888)-300)";
	// Answer : 101382	

	//char str[] = "-10-((-2+(2+4*3))-12)";
	// Answer : -10
	
	// Print arranged input with postfix and calculated output
	std::cout << Eval(str) << std::endl;
		
	return 0;
}
