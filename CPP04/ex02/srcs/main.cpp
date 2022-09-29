/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:12:42 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 17:04:46 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


int main(){

	Animal* animals[20];

	for (int i = 0; i < 10; i++)
		animals[i] = new Dog();
	for (int i = 10; i < 20; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 20; i++)
		delete animals[i];
		
	
	// const Animal* meta = new Animal();
	// const Animal* i = new Cat();
	// const Animal* j = new Dog();
	// const WrongAnimal* k = new WrongCat();
	// const WrongAnimal* meta2 = new WrongAnimal();



	// i->makeSound();
	// j->makeSound();
	// k->makeSound();
	// meta->makeSound();
	// meta2->makeSound();

	// delete meta;
	// delete meta2;
	// delete i;
	// delete j;
	// delete k;
	return (0);
};