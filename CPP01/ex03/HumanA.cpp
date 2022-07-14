/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:07:15 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 01:54:31 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::set_name( std::string name ){
	this->_name = name;
}

void HumanA::attack( void ){
	std::cout << this->_name << " attacks with their " <<  this->_weapon.getType() << std::endl;
}

HumanA::HumanA( std::string name, Weapon &weapon ): _name(name), _weapon(weapon){
    
};

HumanA::~HumanA( void ){};