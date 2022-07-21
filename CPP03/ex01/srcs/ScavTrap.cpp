/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:10:01 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 01:32:12 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

void ScavTrap::attack( const std::string& target ){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
	}
	else if (this->_hp <= 0) {
		std::cout << this->_name << " is dead" << std::endl;
	}
	else {
		std::cout << this->_name << " hasn t enough mana to attack" << std::endl;
	}
};


ScavTrap::ScavTrap(const ScavTrap &ScavTrap){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = ScavTrap;
	return;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_hp = rhs._hp;
		_mana = rhs._mana;
		_ad = rhs._ad;
	}
	return (*this);
}

void	ScavTrap::guardGate(void){
	if (this->_hp <= 0){
		std::cout << this->_name << " is dead." << std::endl;
		return ;
	}
	if (_odor == false){
		std::cout << this->_name << " is in Odor mode" << std::endl;
		_odor = true;
	}
	else {
		std::cout << this->_name << " is not in Odor mode anymore" << std::endl;
		_odor = false;
	}
};

int ScavTrap::getHp(){
	std::cout << "hp = " << this->_hp << std::endl;
	return (this->_hp);	
};

ScavTrap::ScavTrap( std::string name ): ClapTrap(name){
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_ad = 20;
    this->_hp = 100;
    this->_mana = 50;
	this->_odor = false;
};

ScavTrap::~ScavTrap( void ){
    std::cout << "ScavTrap destructor called" << std::endl;
};