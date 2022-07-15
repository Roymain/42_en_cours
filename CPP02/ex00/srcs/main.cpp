/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:11:12 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/15 04:38:44 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main(void)
{
	Fixed 	a;

	a.setRawBits(120);
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	Fixed	b(a);
	Fixed	c;
	c = b;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}