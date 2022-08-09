/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:37:06 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/09 21:37:07 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Zombie.hpp"

std::string Zombie::get_name( void ){
     return (this->_name);
}

void Zombie::set_name( std::string name ){
	this->_name = name;
}

void Zombie::announce( void ){
    std::cout << this->_name << ": BraiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ){
    this->_name = "unnamed";
};

Zombie::Zombie( std::string name) : _name(name){};

Zombie :: ~Zombie( void ){
    std::cout << this->_name << ": destroyed" << std::endl;
};
