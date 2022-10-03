/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:05:39 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 04:13:25 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Brain.hpp"

std::string* Brain::getIdeas( void )
{
	return(this->_ideas);
}

Brain::Brain(const Brain &brain){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
	return;
}

Brain &Brain::operator = (const Brain &brain){
	std::cout << "Brain copy operator called" << std::endl;
	if (&brain != this)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = brain._ideas[i];
	}
	return (*this);
}



Brain::Brain(void){
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Have no idea!";
	return ;
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
	return ;
}