/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 05:04:28 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"


Cat::Cat(const Cat &Cat){
	*this = Cat;
	return;
}

Cat &Cat::operator = (const Cat &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_type = rhs._type;
		_point = rhs._point;
	}
	return (*this);
}

Brain *Cat::getBrain(void) const {
	return (this->_point);
}

Cat::Cat( void ): Animal("unnamed", "Cat") {
    std::cout << "A Cat constructor has been called for unnamed" << std::endl;
    this->_type = "Cat";
	this->_point = new Brain( "unnamed" );
};

Cat::Cat( std::string name, std::string type ): Animal(name, type) {
    std::cout << "A Cat constructor has been called for " << name << std::endl;
    this->_name = name;
    this->_type = type;
	this->_point = new Brain( this->_name );
};


Cat::~Cat( void ){
    std::cout << "A Cat destructor has been called" << std::endl;
	delete this->_point;
};