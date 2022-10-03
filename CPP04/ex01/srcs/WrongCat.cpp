/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 03:59:32 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

void WrongCat::makeSound( void ) const {
	std::cout << "uuuuoooaiM!" << std::endl;
}



WrongCat::WrongCat(const WrongCat &Cat){
	*this = Cat;
	return;
}

WrongCat &WrongCat::operator = (const WrongCat &rhs){
	if (&rhs != this)
	{
		_type = rhs._type;
	}
	return (*this);
}



WrongCat::WrongCat( void ): WrongAnimal() {
    std::cout << "A wrongCat constructor has been called" << std::endl;
};

WrongCat::~WrongCat( void ){
    std::cout << "A wrongCat destructor has been called" << std::endl;
};