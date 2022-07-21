/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:25:54 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 02:07:53 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main(){

	ScavTrap Scavo = ScavTrap("Scavo");

	Scavo.getHp();
	Scavo.takeDamage(80);
	Scavo.beRepaired(40);
	Scavo.takeDamage(20);
	Scavo.beRepaired(10);
	Scavo.takeDamage(120);

	ClapTrap Tom = ClapTrap("tom");
	
	Tom.takeDamage(5);
	Tom.takeDamage(5);
	Tom.beRepaired(5);
	
	Scavo.guardGate();
	Scavo.guardGate();
	Scavo.guardGate();
	Scavo.guardGate();
	Scavo.guardGate();

	
	return (0);
}; 