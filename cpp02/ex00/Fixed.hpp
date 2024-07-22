#ifndef FIXED_H
# define FIXED_H

class Fixed
{

	private:

		int					_fix;
		static const int	_fracBits = 8;

	public:

		Fixed(void);
		Fixed(Fixed const & src); //copy constructor
		~Fixed(void);

		Fixed & operator=(Fixed const & src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif