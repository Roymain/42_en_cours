/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:58 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:13:19 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void Dog::makeSound( void ) const {
	std::cout << "Whouuuf!" << std::endl;
}




Dog::Dog(const Dog &Dog){
	*this = Dog;
	return;
}

Dog &Dog::operator = (const Dog &rhs){
	if (&rhs != this)
		_type = rhs._type;
	return (*this);
}




Dog::Dog( void ){
    std::cout << "A Dog default constructor has been called" << std::endl;
    this->_type = "Dog";
};

Dog::Dog( std::string type ){
    std::cout << "A Dog constructor has been called for " << type << std::endl;
    this->_type = type;
};


Dog::~Dog( void ){
    std::cout << "A Dog destructor has been called" << std::endl;
};