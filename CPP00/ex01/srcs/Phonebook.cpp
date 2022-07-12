/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:25:22 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/12 03:55:57 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.Class.hpp"
#include "Contact.class.hpp"
#include <iomanip>


std::string Phonebook::ft_getline( void ){
	getline(std::cin, this->_line);
	if (std::cin.eof())
		return (NULL);
	return (this->_line);
};

void Phonebook::ft_add( void ){
	if (_incrementeur == 8)
		_incrementeur = 0;
	ft_firstname();
	ft_lastname();
    ft_nickname();
 	ft_phonenumber();
	_incrementeur++;
};

static std::string	ft_format_char(std::string s)
{
	std::string	s1;
	s1 = s;
	if (s1.size() > 10)
	{
		s1[9] = '.';
		s1.resize(10);
	}
	return (s1);
}

void Phonebook::ft_printsearch( int index){
	std::cout << _Contact[index].get_firstname() << "; " ;
	std::cout << _Contact[index].get_lastname() << "; " ;
	std::cout << _Contact[index].get_nickname() << "; " ;
	std::cout << _Contact[index].get_phonenumber() << "; " << std::endl;
	
}

void Phonebook::ft_search(){
	int	index = 0;
	int i = 0;
	while (!this->_Contact[i].present() ){
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		std::cout << "|" << std::setw(10) << std::right << ft_format_char(_Contact[i].get_firstname());
		std::cout << "|" << std::setw(10) << ft_format_char(this->_Contact[i].get_lastname());
		std::cout << "|" << std::setw(10) << ft_format_char(this->_Contact[i].get_nickname()) << "|" << std::endl;		
		i++;
	}
	std::cout << "quel index?" << std::endl;
	ft_getline();
	if (std::isdigit(_line[0])){
		index = std::stoi( _line );
		if (index < 1 || index > i )
			this->ft_search();
		else
			this->ft_printsearch(index - 1);
	}
	else
		this->ft_search();
}

void Phonebook::run(){
	ft_getline();
	while( this->_line != "EXIT" ){
		if (this->_line == "ADD")
			ft_add();
		else if (this->_line == "SEARCH")
			ft_search();
		ft_getline();
	}
};

void Phonebook::ft_firstname( void ){

	std::cout << "Saisir le prenom :" << std::endl;
	_Contact[_incrementeur].set_firstname(ft_getline());
	
};

void Phonebook::ft_lastname( void ){

	std::cout << "Saisir le nom :" << std::endl;
	_Contact[_incrementeur].set_lastname(ft_getline());
	
};

void Phonebook::ft_nickname( void ){

	std::cout << "Saisir le surnom :" << std::endl;
	_Contact[_incrementeur].set_nickname(ft_getline());
	
};

void Phonebook::ft_phonenumber( void ){

	std::cout << "Saisir le numero de telephone :" << std::endl;
	_Contact[_incrementeur].set_phonenumber(ft_getline());
	
};

Phonebook::Phonebook( void ) : _incrementeur(0) {};

Phonebook::~Phonebook( void ){};
