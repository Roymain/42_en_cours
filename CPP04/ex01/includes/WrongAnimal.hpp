/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:16:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 03:58:20 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal {
	protected:
			std::string		_type;
	public:
			void makeSound( void ) const;

			WrongAnimal & operator = (const WrongAnimal &rhs);
			WrongAnimal(const WrongAnimal &Animal);
			
			WrongAnimal( void );
			virtual ~WrongAnimal( void );
			
};

#endif