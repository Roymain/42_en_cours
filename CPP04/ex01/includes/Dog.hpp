/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:11 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 05:56:19 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal {
	protected:
			std::string		_type;
			Brain*			_point;
			
	public:
			virtual void makeSound( void ) const;
			virtual Brain *getBrain(void) const;
			
			Dog & operator = (const Dog &rhs);
            Dog(const Dog &Dog);
            
			Dog( void );       
			virtual ~Dog( void );
			
};

#endif