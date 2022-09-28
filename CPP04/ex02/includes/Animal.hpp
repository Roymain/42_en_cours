/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:16:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 05:41:22 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Brain.hpp"

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal {
	protected:
			std::string		_name;
			std::string		_type;
	public:
			
			void makeSound( void ) const;

			Animal & operator = (const Animal &rhs);
			Animal(const Animal &Animal);
			
			
			Animal( void );
			Animal( std::string name, std::string type );
			virtual ~Animal( void );
			
			
};

#endif