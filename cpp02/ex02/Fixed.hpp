#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{

	private:

		int					_fix;
		static const int	_fracBits = 8;

	public:

		Fixed(void);
		Fixed(const int param);
		Fixed(const float param);
		Fixed(Fixed const & src); //copy constructor
		~Fixed(void);
		
		//ARITHMETIC	
		Fixed & operator=(Fixed const & src); //operator = overload
		Fixed	operator+(Fixed const & src);
		Fixed	operator-(Fixed const & src);
		Fixed	operator*(Fixed const & src);
		Fixed	operator/(Fixed const & src);

		//COMPARISON
		bool	operator>(Fixed const & src) const;
		bool	operator<(Fixed const & src) const;
		bool	operator>=(Fixed const & src) const;
		bool	operator<=(Fixed const & src) const;
		bool	operator==(Fixed const & src) const;
		bool	operator!=(Fixed const & src) const;

		//INCREMENT - DECREMENT
		Fixed &	operator++(); 		//prefix operator ++ overload
		Fixed	operator++(int);	//postfix operator ++ overload
		Fixed & operator--();		//prefix operator -- overload
		Fixed	operator--(int);	//postfix operator -- overload

		//FUNCTIONS
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed & min(Fixed & num1, Fixed & num2);
		static const Fixed & min(Fixed const &  num1, Fixed const & num2);
		static Fixed & max(Fixed & num1, Fixed & num2); 
		static const Fixed & max(Fixed const & num1, Fixed const & num2);

};

std::ostream & operator<<(std::ostream & o, Fixed const & src); //operator << overload

#endif