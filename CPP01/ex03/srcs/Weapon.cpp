/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:28:30 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 00:57:45 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

const std::string& Weapon::getType() const{
    return (this->_type);
};

void Weapon::setType(std::string newtype){
	this->_type = newtype;
};

Weapon::Weapon(std::string type): _type(type){};
Weapon::~Weapon( void ){};

