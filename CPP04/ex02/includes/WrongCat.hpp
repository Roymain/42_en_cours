/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:20:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:14:32 by Romain           ###   ########.fr       */
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
			virtual void makeSound( void ) const;
			
			WrongCat & operator = (const WrongCat &rhs);
            WrongCat(const WrongCat &Cat);
            
			WrongCat( void );
			WrongCat( std::string type );
			virtual ~WrongCat( void );
			
};

#endif