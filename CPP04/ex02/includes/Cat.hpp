/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:20:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 05:56:14 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal {
	protected:
			std::string		_type;
			Brain*			_point;

	public:
			virtual void makeSound( void ) const;
			virtual Brain *getBrain(void) const;
			
			Cat & operator = (const Cat &rhs);
            Cat(const Cat &Cat);
            
			Cat( void );
			virtual ~Cat( void );
			
};

#endif