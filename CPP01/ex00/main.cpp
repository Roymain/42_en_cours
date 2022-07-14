/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:38:59 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/13 22:41:46 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    
    Zombie *z = new Zombie("roger");
    
	z->announce();

	delete z;
	
    z = newZombie("alphonse");
	
	randomChump("steph");

	delete z;
	
	return (0);
    
}