/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:20:03 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 03:22:30 by rcuminal         ###   ########.fr       */
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
			
			WrongCat & operator = (const WrongCat &rhs);
            WrongCat(const WrongCat &Cat);
            
			WrongCat( void );
			WrongCat( std::string type );
			~WrongCat( void );
			
};

#endif