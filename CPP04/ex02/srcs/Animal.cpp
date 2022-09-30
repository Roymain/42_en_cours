/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:52 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/30 16:18:58 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"


Animal::Animal(const Animal &Animal){
	*this = Animal;
	return;
}

Animal & Animal::operator = (const Animal &rhs){
	if (&rhs != this)
		_type = rhs._type;
	return (*this);
}




Animal::Animal( void ){
    std::cout << "An animal default constructor has been called" << std::endl;
};

Animal::Animal( std::string type ): _type(type){
    std::cout << "An animal constructor has been called for " << type << std::endl;
	this->_type = type;
};


Animal::~Animal( void ){
    std::cout << "An animal destructor has been called" << std::endl;
};