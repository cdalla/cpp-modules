#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN const &src)
{
	*this = src;
	return ;
}

RPN& RPN::RPN::operator=(RPN const &src)
{
	this->opContainer = src.opContainer;
	return *this;
}

bool	isSign(char c)
{
	return  (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::calculation(char c)
{
	double  operand = opContainer.top();
	opContainer.pop();
	std::cout << opContainer.top() << " " << c << " " << operand << std::endl;
	switch (c)
	{
		case '+':
			opContainer.top() += operand;
			break;
		case '-':
			opContainer.top() -= operand;
			break;
		case '*':
			opContainer.top() *= operand;
			break;
		case '/':
		{
			if (!operand)
				throw std::runtime_error("Invalid division by zero");
			opContainer.top() /= operand;
			break;	
		}
	}
}

double RPN::calculate(const std::string &operation)
{
	for(size_t i = 0; i < operation.length(); i++)
	{
		char c = operation[i];
		if (std::isdigit(c))
		{
			int operand = c - '0';
			opContainer.push(operand);
		}
		else if (isSign(c))
		{
			if (opContainer.size() < 2)
				throw std::runtime_error("Invalid expression");
			calculation(c);
		}
		else if (c != ' ')
			throw std::runtime_error("Invalid char in expression");
	}
	if (opContainer.size() != 1)
		throw std::runtime_error("Invalid expression");
	return opContainer.top();
}
