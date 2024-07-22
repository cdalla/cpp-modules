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

		Fixed & operator=(Fixed const & src);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
 
};

std::ostream & operator<<(std::ostream & o, Fixed const & src); //operator << overload

#endif