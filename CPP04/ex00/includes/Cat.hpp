/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:20:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 03:49:00 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/Animal.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal {
	public:
			virtual void makeSound( void ) const;
			
			Cat & operator = (const Cat &rhs);
            Cat(const Cat &Cat);
            
			Cat( void );
			virtual ~Cat( void );
			
};

#endif