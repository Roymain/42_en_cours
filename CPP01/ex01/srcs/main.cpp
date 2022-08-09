/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:38:59 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/09 21:43:30 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(){
    
	Zombie *zombax;
	
	zombax = zombieHorde(5, "roger");
	std::cout << "CHYbrcyrt" << std::endl;
	zombax[1].announce();
	std::cout << "zomb 3 = " << zombax[2].get_name() << std::endl;
	zombax[2].set_name("albert");
	zombax[2].announce();

	
	delete []zombax;
	
	return (0);
    
}