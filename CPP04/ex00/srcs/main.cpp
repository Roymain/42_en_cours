/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:12:42 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:31:48 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


int main(){
	
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* meta2 = new WrongAnimal();



	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	meta2->makeSound();

	delete meta;
	delete meta2;
	delete i;
	delete j;
	delete k;
	return (0);
};