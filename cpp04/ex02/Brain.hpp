#ifndef BRAIN_H
# define BRAIN_H

#include <string>
#include <array>

class Brain
{
	protected:

		std::string _ideas[100];
	
	public:

		Brain();
		Brain(std::string idea);
		Brain(Brain const & src);
		~Brain();

		Brain & operator=(Brain const & src);
		
		std::string getIdeas(int index) const;
		void 		setIdeas(std::string idea, int index);
};


#endif