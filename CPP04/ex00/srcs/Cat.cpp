/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:13:10 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void Cat::makeSound( void ) const {
	std::cout << "Miaaaouu!" << std::endl;
}




Cat::Cat(const Cat &Cat){
	*this = Cat;
	return;
}

Cat &Cat::operator = (const Cat &rhs){
	if (&rhs != this)
		_type = rhs._type;
	return (*this);
}





Cat::Cat( void ){
    std::cout << "A Cat default constructor has been called" << std::endl;
    this->_type = "Cat";
};

Cat::Cat( std::string type ){
    std::cout << "A Cat constructor has been called for " << type << std::endl;
    this->_type = type;
};

Cat::~Cat( void ){
    std::cout << "A Cat destructor has been called" << std::endl;
};