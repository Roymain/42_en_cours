/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:12:42 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 05:41:42 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


int main(){
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog("Brutus", "Dog");
	const Animal* i = new Cat("Roger", "Cat");

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
//	delete j->getBrain();
	delete j;
	delete i;
	delete meta;
	return (0);
};