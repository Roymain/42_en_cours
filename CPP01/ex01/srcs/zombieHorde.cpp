/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:45:22 by rcuminal          #+#    #+#             */
/*   Updated: 2022/08/09 21:37:05 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

	int i = 0;

	Zombie *zomb;
    zomb = new Zombie[N];
	for (; i < N; i++ ){
		zomb[i].set_name(name);
		zomb[i].announce();
   }
   return zomb;
};