#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

// namespace RPN
// {	
// 	double	calculate(const std::string &operation);
// };


class RPN
{
	private:
			
			std::stack<double> opContainer;
			
	public:
	
			RPN();
			RPN(RPN const &src);
			~RPN();
			
			RPN &operator=(RPN const &src);
			
			double	calculate(const std::string &operation);
			void	calculation(char c);
};

#endif