/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:54:46 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/12 03:54:20 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

std::string Contact::get_firstname( void ){
     return (this->_first_name);
}

std::string Contact::get_lastname( void ){
    return (this->_last_name);
}

std::string Contact::get_nickname( void ){
     return (this->_nickname);
}

std::string Contact::get_phonenumber( void ){
     return (this->_phonenumber);
}

void Contact::set_firstname( std::string firstname ){
	this->_first_name = firstname;
}

void Contact::set_lastname( std::string lastname ){
    this->_last_name = lastname;
}

void Contact::set_nickname( std::string nickname ){
    this->_nickname = nickname;
}

void Contact::set_phonenumber( std::string phonenumber ){
    this->_phonenumber = phonenumber;
}

bool Contact::present( void ){
	return(_first_name.empty());
}

Contact::Contact( ){};

Contact :: ~Contact( void ){};
