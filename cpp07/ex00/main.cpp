#include "whatever.hpp"
#include <iostream>

int main( void ) 
{
	int a = 2;
	int b = 3;
	
	std::cout << "START: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "AFTER SWAP: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "START: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	
	std::cout << "AFTER SWAP: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	// //USING DIFFERENT TYPES WILL CAUSE AN ERROR
	// int		e = 2;
	// float	f = 3.0f;
	
	// ::swap( e, f );
	// std::cout << "a = " << e << ", b = " << f << std::endl;
	// std::cout << "min( a, b ) = " << ::min( e, f ) << std::endl;
	// std::cout << "max( a, b ) = " << ::max( e, f ) << std::endl;
	
	return 0;
}