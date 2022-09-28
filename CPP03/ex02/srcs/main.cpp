/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:25:54 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 00:43:03 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main(){

	ScavTrap Scavo = ScavTrap("Scavo");

	std::cout << Scavo.getHp() << std::endl;
	Scavo.takeDamage(80);
	Scavo.beRepaired(40);
	Scavo.takeDamage(20);
	Scavo.beRepaired(10);
	//Scavo.takeDamage(120);
	Scavo.guardGate();
	Scavo.guardGate();
	Scavo.guardGate();
	Scavo.guardGate();
	Scavo.guardGate();

	ClapTrap Tom = ClapTrap("tom");
	
	Tom.takeDamage(5);
	
	
	Tom.takeDamage(120);
	Tom.attack("jean eude");

	FragTrap	Linette = FragTrap("linette");

	std::cout << Linette.getHp() << std::endl;
	Linette.takeDamage(15);
	std::cout << Linette.getHp() << std::endl;
	Linette.highFivesGuys();

	
	return (0);
}; 