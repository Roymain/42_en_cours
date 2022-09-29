/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:33:00 by Romain           ###   ########.fr       */
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



WrongCat::WrongCat( void ): WrongAnimal("WrongCat") {
    std::cout << "A wrongCat constructor has been called" << std::endl;
    this->_type = "WrongCat";
};

WrongCat::WrongCat( std::string type ): WrongAnimal(type) {
    std::cout << "A wrongCat constructor has been called" << std::endl;
    this->_type = type;
};


WrongCat::~WrongCat( void ){
    std::cout << "A wrongCat destructor has been called" << std::endl;
};