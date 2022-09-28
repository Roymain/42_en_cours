/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:15:43 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 00:07:22 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


void ClapTrap::attack( const std::string& target ){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
	}
	else if (this->_hp <= 0) {
		std::cout << this->_name << " is dead" << std::endl;
	}
	else {
		std::cout << this->_name << " hasn t enough mana to attack" << std::endl;
	}
};

void ClapTrap::takeDamage( unsigned int amount ){
	std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
	this->_hp -= amount;
};

int ClapTrap::getHp(){
	std::cout << "hp = " << this->_hp << std::endl;
	return (this->_hp);	
};

void ClapTrap::beRepaired( unsigned int amount ){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "ClapTrap " << this->_name << " recover " << amount << " HP!" << std::endl;
		this->_hp += amount;
		this->_mana--;
	}
	else if (this->_hp <= 0) {
		std::cout << this->_name << " is dead" << std::endl;
	}
	else {
		std::cout << this->_name << " hasn t enough mana to repair himself" << std::endl;
	}
};

ClapTrap::ClapTrap(const ClapTrap &ClapTrap){
	*this = ClapTrap;
	return;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_hp = rhs._hp;
		_mana = rhs._mana;
		_ad = rhs._ad;
	}
	return (*this);
}




ClapTrap::ClapTrap( void ): _hp(10), _mana(10), _ad(0){
	std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hp(10), _mana(10), _ad(0){
	std::cout << "constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void ){
	std::cout << this->_name << "'s destructor called" << std::endl;
}