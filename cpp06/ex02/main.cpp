#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

Base * generate(void)
{
	Base *ptr;
	
	switch(std::rand() % 4)
	{
		case 0:
		{
			ptr = new A;
			std::cout << "Class A instance created" << std::endl;
			break ;
		}
		case 1:
		{
			ptr = new B;
			std::cout << "Class B instance created" << std::endl;
			break ;
		}
		case 2:
		{
			ptr = new C;
			std::cout << "Class C instance created" << std::endl;
			break ;
		}
		case 3:
		{
			ptr = nullptr;
			std::cout << "Null pointer created" << std::endl;
			break ;
		}
	}
	return ptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Identify pointer: Pointer of class A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Identify pointer: Pointer of class B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Identify pointer: Pointer of class C" << std::endl;
	}
	else
		std::cout << "The pointer is none of these types" << std::endl;
	return ;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identify reference: Reference of class A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << "Cast to type A failed" << std::endl;		
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identify reference: Reference of class B" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << "Cast to type B failed" << std::endl;	
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identify reference: Reference of class C" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << "Cast to type C failed" << std::endl;	
	}
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
	{
		Base * base = generate();
		identify(base);
		identify(*base);
		
		delete base;
		std::cout << "\n";
	}
	return 0;
}