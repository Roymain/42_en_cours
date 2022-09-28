/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:21:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 00:27:07 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

void FragTrap::attack( const std::string& target ){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
	}
	else if (this->_hp <= 0) {
		std::cout << this->_name << " is dead" << std::endl;
	}
	else {
		std::cout << this->_name << " hasn t enough mana to attack" << std::endl;
	}
};


FragTrap::FragTrap(const FragTrap &FragTrap){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = FragTrap;
	return;
}

FragTrap &FragTrap::operator = (const FragTrap &rhs){
	if (&rhs != this)
	{
		_name = rhs._name;
		_hp = rhs._hp;
		_mana = rhs._mana;
		_ad = rhs._ad;
	}
	return (*this);
}

int FragTrap::getHp(){
	std::cout << "hp = " << this->_hp << std::endl;
	return (this->_hp);	
};

void highFivesGuys(void){
    std::cout << "high five bro?!?" << std::endl;
};

FragTrap::FragTrap( void ): ClapTrap("default"){
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_ad = 30;
    this->_hp = 100;
    this->_mana = 100;
};

FragTrap::FragTrap( std::string name ): ClapTrap(name){
    std::cout << "FragTrap constructor called" << std::endl;
    this->_ad = 30;
    this->_hp = 100;
    this->_mana = 100;
};

FragTrap::~FragTrap( void ){
    std::cout << "FragTrap destructor called" << std::endl;
};