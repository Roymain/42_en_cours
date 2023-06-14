/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:15:43 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 02:58:51 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

bool	ft_check(char *str){
	if (std::isalpha(str[0]) && str[1])
		return (false);
	return (true);
};


int main(int argc, char **argv){
	
	if (argc != 2)
	{
		std::cout << "no or too much args!" << std::endl; 
		return (1);
	}
	if (!ft_check(argv[1]))
	{
		std::cout << "invalid arg!" << std::endl; 
		return (1);
	}
	Convert converter = Convert(argv[1]);

	converter.toChar();
	converter.toInt();
	converter.toFloat();
	converter.toDouble();
	
	
	return (0);
};
