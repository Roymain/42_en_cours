/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:58 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 03:51:04 by rcuminal         ###   ########.fr       */
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




Dog::Dog( void ) : Animal("dog"){
    std::cout << "A Dog default constructor has been called" << std::endl;
};

Dog::~Dog( void ){
    std::cout << "A Dog destructor has been called" << std::endl;
};