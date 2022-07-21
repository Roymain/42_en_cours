/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:16:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 03:01:02 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
			~Animal( void );
			
};

#endif