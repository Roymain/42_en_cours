/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:46 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 02:59:08 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

void Convert::toChar(){
	if (!this->_arg[1] && !std::isdigit(this->_arg[0]))
	{
		std::cout << "char: already a char : " << _arg[0] << std::endl;
		return;
	}
	int nbr = std::stoi(this->_arg);
	if (std::isprint(nbr) == true)
		std::cout << "char: " << static_cast<char>(nbr) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
};

void Convert::toInt(){
	int nbr;
	
	if (!this->_arg[1] && std::isalpha(this->_arg[0])){
		std::cout << "int: " << static_cast<int>(this->_arg[0]) << std::endl;
		return;
	}	
	nbr = std::stoi(this->_arg);
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
};

void Convert::toFloat(){
	float nbr;
	std::string::size_type sz;
	
	if (!this->_arg[1] && std::isalpha(this->_arg[0])){
		std::cout << "float: " << static_cast<float>(this->_arg[0]) << std::endl;
		return;
	}	
	nbr = stof(this->_arg, &sz);
	int index;
	index = this->_arg.find(".");
	std::cout.precision((this->_arg.length() - index));
	std::cout << "float: " << nbr ;
	if (nbr - static_cast<int>(nbr) == 0.0)
		std::cout << ".0" ;
	std::cout << "f" << std::endl;
	std::cout.precision(0);
};

void Convert::toDouble(){
	double	nbr;
	int		index;
	
	if (!this->_arg[1] && std::isalpha(this->_arg[0])){
		std::cout << "double: " << static_cast<double>(this->_arg[0]) << std::endl;
		return;
	}	
	nbr = std::stod(this->_arg);
	index = this->_arg.find(".");
	std::cout.precision((this->_arg.length() - index));
	std::cout << "double: " << nbr;
	if (nbr - static_cast<int>(nbr) == 0.0)
		std::cout << ".0" ;
	std::cout << std::endl;
	std::cout.precision(0);
};




Convert::Convert( char *arg): _arg(arg) {};

Convert::~Convert(){};