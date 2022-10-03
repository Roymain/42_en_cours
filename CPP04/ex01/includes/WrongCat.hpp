/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:20:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 03:57:42 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../includes/WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat : public WrongAnimal {
	protected:
			std::string		_type;
	public:
			void makeSound( void ) const;
			
			WrongCat & operator = (const WrongCat &rhs);
            WrongCat(const WrongCat &Cat);
            
			WrongCat( void );
			virtual ~WrongCat( void );
			
};

#endif