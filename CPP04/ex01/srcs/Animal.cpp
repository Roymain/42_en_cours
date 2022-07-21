/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:52 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 04:37:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void Animal::makeSound( void ) const {
	if ( this->_type == "Dog")
		std::cout << this->_type << ": Whooooouuuuf!" << std::endl;
	else if (this->_type == "Cat")  
		std::cout << this->_type << ": Miaaouuuuuu!" << std::endl;
	else
		std::cout << "wtf?!" << std::endl;
}

Animal::Animal(const Animal &Animal){
	*this = Animal;
	return;
}

Animal & Animal::operator = (const Animal &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_type = rhs._type;
	}
	return (*this);
}

Animal::Animal( void ){
    std::cout << "An animal constructor has been called for unnamed" << std::endl;
};

Animal::Animal( std::string name, std::string type ): _name(name), _type(type){
    std::cout << "An animal constructor has been called for " << name << std::endl;
	this->_name = name;
	this->_type = type;
};


Animal::~Animal( void ){
    std::cout << "An animal destructor has been called" << std::endl;
};