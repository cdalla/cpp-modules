/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdalla-s <cdalla-s@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 16:13:12 by cdalla-s      #+#    #+#                 */
/*   Updated: 2023/07/25 12:27:27 by cdalla-s      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->setIdeas("sti c***i non ho idee", i);
	return ;
}

Brain::Brain(std::string idea)
{
	std::cout << "Brain constructor with parameter called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->setIdeas(idea, i);
	return ;
}

Brain::Brain(Brain const & src)
{
	*this = src;

	std::cout << "Brain copy constructor called" << std::endl;

	return ;
}
		
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;

	return ;
}

Brain & Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdeas(i);
	
	std::cout << "Brain copy assignment operator called" << std::endl;

	return *this;
}

std::string Brain::getIdeas(int index) const
{
	return	this->_ideas[index];
}

void	Brain::setIdeas(std::string idea, int index)
{
	this->_ideas[index] = idea;

	return ;
}
