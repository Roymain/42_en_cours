/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 03:26:44 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


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
    std::cout << "A Cat constructor has been called" << std::endl;
    this->_type = "WrongCat";
};

WrongCat::WrongCat( std::string type ): WrongAnimal(type) {
    std::cout << "A Cat constructor has been called" << std::endl;
    this->_type = type;
};


WrongCat::~WrongCat( void ){
    std::cout << "A Cat destructor has been called" << std::endl;
};