/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:11 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 05:40:34 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal {
	protected:
			std::string		_name;
			std::string		_type;
			Brain*			_point;
	public:
			
			virtual Brain *getBrain(void) const;
			
			Dog & operator = (const Dog &rhs);
            Dog(const Dog &Dog);
            
			
			
			Dog( void );
			Dog( std::string name, std::string type );
            
			virtual ~Dog( void );
			
};

#endif