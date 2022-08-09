/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:38:59 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/09 21:34:40 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(){
    
    Zombie *z = new Zombie("roger");
    
	z->announce();

	delete z;
	
    Zombie *x = newZombie("alphonse");
	x->announce();
	
	randomChump("steph");

	delete x;
	
	return (0);
    
}