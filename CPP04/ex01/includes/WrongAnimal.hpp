/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:16:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:25:29 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal {
	protected:
			std::string		_type;
	public:
			virtual void makeSound( void ) const;

			WrongAnimal & operator = (const WrongAnimal &rhs);
			WrongAnimal(const WrongAnimal &Animal);
			
			WrongAnimal( void );
			WrongAnimal( std::string type );
			virtual ~WrongAnimal( void );
			
};

#endif