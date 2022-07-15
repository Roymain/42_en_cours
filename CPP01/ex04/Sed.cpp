/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 03:01:21 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 22:33:34 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void Sed::replaceator( std::string line, size_t size ){
    size_t i;

    i = 0;
    for (; i < size; i++)
        this->_replaced << line[i];
    this->_replaced << this->_s2;
    line.erase(0, i + this->_s1.length());
    this->_replaced << line << std::endl;

};
 
void Sed::replicator( std::string line ){
    if ( line.find(this->_s1)  )
        this->_replaced << line << std::endl;
    else
        replaceator(line, line.find(this->_s1));
};

void Sed::closing( void ){
	this->_replaced.close();
};

Sed::Sed( void ){};

Sed::Sed( std::string s1, std::string s2, std::string replaced ): _s1(s1), _s2(s2) {
	
    this->_replaced.open(replaced + ".replace", std::fstream::out | std::fstream::trunc);
};

Sed::~Sed( void ){};