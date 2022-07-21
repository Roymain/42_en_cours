/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:13:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/15 23:33:37 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int Fixed::getRawBits( void ) const {
	return this->_value;
};

void Fixed::setRawBits( int const raw ){
	this->_value = raw;
};

float Fixed::toFloat( void ) const{
	return (this->_value / pow(2, this->_fractiobits));
};

int Fixed::toInt( void ) const{
	return (this->_value / pow(2, this->_fractiobits));
};




Fixed & Fixed::operator = ( const Fixed  &fixed){
	this->_value = fixed.getRawBits();
	return (*this);
};

Fixed Fixed::operator + (const Fixed  &fixed) const{
	return (this->toFloat() + fixed.toFloat());
};

Fixed Fixed::operator - (const Fixed  &fixed) const{
	return (this->toFloat() - fixed.toFloat());
};

Fixed Fixed::operator * (const Fixed  &fixed) const{
	return (this->toFloat() * fixed.toFloat());
};

Fixed Fixed::operator / (const Fixed  &fixed) const{
	return (this->toFloat() / fixed.toFloat());
};

	
			
bool Fixed::operator == (const Fixed  &fixed){
	return (this->_value == fixed._fractiobits);
};

bool Fixed::operator != (const Fixed  &fixed){
	return (this->_value != fixed._fractiobits);
};

bool Fixed::operator < (const Fixed  &fixed){
	return (this->_value < fixed._fractiobits);
};

bool Fixed::operator <= (const Fixed  &fixed){
	return (this->_value <= fixed._fractiobits);
};
bool Fixed::operator > (const Fixed  &fixed){
	return (this->_value > fixed._fractiobits);
};

bool Fixed::operator >= (const Fixed  &fixed){
	return (this->_value >= fixed._fractiobits);
};



Fixed & Fixed::operator ++ ( void ){
	this->_value++;
	return (*this);
};

Fixed Fixed::operator ++ ( int value ){
	Fixed tmp = *this;
	operator++();
	return tmp;
};

Fixed & Fixed::operator -- ( void ){
	this->_value--;
	return (*this);
};

Fixed Fixed::operator -- ( int value ){
	Fixed tmp = *this;
	operator--();
	return tmp;
};

Fixed & Fixed::max( Fixed &lhs, Fixed &rhs){
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	return rhs;
};

Fixed const & Fixed::max( const Fixed &lhs, const Fixed &rhs){
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	return rhs;
};

Fixed & Fixed::min( Fixed &lhs, Fixed &rhs){
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	return rhs;
};

Fixed const & Fixed::min( const Fixed &lhs, const Fixed &rhs){
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	return rhs;
};

Fixed::Fixed( Fixed const &copy ){
	*this = copy;
};

Fixed::Fixed( void ): _value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const int value ): _value(value * pow(2, this->_fractiobits)){
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed( const float value ){
	std::cout << "Float constructor called" << std::endl;
	this->_value = round(value * pow(2, this->_fractiobits));
};

Fixed::~Fixed( void ){
};



std::ostream & operator << ( std::ostream & oper, Fixed const & rhs ){
	oper << rhs.toFloat();
	return oper ;
};