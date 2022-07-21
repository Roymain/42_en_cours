/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:55:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 05:42:27 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain( std::string name ): _name(name) {
	std::cout << "Brain constructor called for " << name << std::endl;
};

Brain::~Brain(){
	std::cout << "Brain destructor called for " << _name << std::endl;
};