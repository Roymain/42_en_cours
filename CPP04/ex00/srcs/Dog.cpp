/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:58 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 03:06:04 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

Dog::Dog(const Dog &Dog){
	*this = Dog;
	return;
}

Dog &Dog::operator = (const Dog &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_type = rhs._type;
	}
	return (*this);
}

Dog::Dog( void ): Animal("unnamed", "Dog") {
    std::cout << "A Dog constructor has been called for" << std::endl;
    this->_type = "Dog";
};

Dog::Dog( std::string name, std::string type ): Animal(name, type) {
    std::cout << "A Dog constructor has been called for" << name << std::endl;
    this->_name = name;
    this->_type = type;
};


Dog::~Dog( void ){
    std::cout << "A Dog destructor has been called" << std::endl;
};