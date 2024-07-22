#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid input" << std::endl;
		return 0;
	}
	try
	{
		RPN myCalc;
		std::cout << myCalc.calculate(argv[1]) << std::endl;		
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

/*

Reverse Polish Notation is a mathematical notation in which operators follow their operands
example:

	3 4 + = 3 + 4
	3 4 - 5 + = 3 - 4 + 5
	
#program take mathematical expr as argument string
#all numbers must be less than 10
#process the expression and output the result
#+ - / *, operands to manage

use a stack to push operand numbers, if during parsing a sign is found
calculate operation on 2 top elements of stack, pop(),
then push result

*/