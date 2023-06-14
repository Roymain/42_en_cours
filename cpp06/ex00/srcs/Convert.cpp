/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:08:46 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/13 18:57:51 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Convert.hpp"

void Convert::toChar(){

	if (std::isprint(_arg[0]) == true && _arg.size() == 1)
		std::cout << "char: " << static_cast<char>(_arg[0]) << std::endl;
	else
	{
		try 
		{
			int nbr = std::stoi(this->_arg);
			if (std::isprint(static_cast<char>(nbr)))
				std::cout << "char: " << static_cast<char>(nbr) << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << "char: impossible" << std::endl;
		}
	}
};

void Convert::toInt(){
	int nbr;

	try 
	{
		nbr = std::stoi(this->_arg);
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	}
	catch(std::exception & e)
	{
		if (_arg.size() == 1)
			std::cout << "int: " << static_cast<int>(_arg[0]) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
};

void Convert::toFloat(){
	float nbr;
	std::string::size_type sz;

	try 
	{
		nbr = stof(this->_arg, &sz);
		
		int index;
		index = this->_arg.find(".");
		std::cout.precision((this->_arg.length() - index));
		std::cout << "float: " << nbr ;
		if (nbr - static_cast<int>(nbr) == 0.0)
			std::cout << ".0" ;
		std::cout << "f" << std::endl;
		std::cout.precision(0);
	}
	catch (std::exception & e)
	{
		if (_arg.size() == 1)
			std::cout << "float: " << static_cast<float>(_arg[0]) << ".0f" <<  std::endl;
		else
			std::cout << "float: impossible" << std::endl;
	}
};

void Convert::toDouble(){
	double	nbr;
	int		index;
	
	if (!this->_arg[1] && std::isalpha(this->_arg[0])){
		std::cout << "double: " << static_cast<double>(this->_arg[0]) << std::endl;
		return;
	}
	try 
	{
		nbr = std::stod(this->_arg);
		index = this->_arg.find(".");
		std::cout.precision((this->_arg.length() - index));
		std::cout << "double: " << nbr;
		if (nbr - static_cast<int>(nbr) == 0.0)
			std::cout << ".0" ;
		std::cout << std::endl;
		std::cout.precision(0);
	}
	catch (std::exception & e)
	{
		if (_arg.size() == 1)
			std::cout << "double: " << static_cast<double>(_arg[0]) << ".0" << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
	}
};

Convert & Convert::operator = ( const Convert & rhs){
	if (&rhs == this)
		_arg = rhs._arg;
	return (*this);
};

Convert::Convert( const Convert & rhs){
	*this = rhs;
	return;
};
			
Convert::Convert(){};

Convert::Convert( char *arg ): _arg(arg) {};

Convert::~Convert(){};