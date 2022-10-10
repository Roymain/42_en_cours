/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:59:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/10 03:20:41 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

void				Span::addNumber( int value ){
	if (_data.size() == _size)
		throw Span::SpanFullException();
	_data.push_back(value);
    std::sort(this->_data.begin(), this->_data.end());
}

unsigned int		Span::shortestSpan(){
	unsigned int tmp = UINT_MAX;
	
	if (_data.size() <= 1)
		throw Span::SpanEmptySetException();
	for (std::vector<int>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		if ((unsigned int)(*(it + 1) - *it) < tmp)
			tmp = (unsigned int)(*(it + 1) - *it);
	}
	return (tmp);
};

unsigned int		Span::longestSpan(){
	if (_data.size() > 1)
		return (*(_data.end() - 1) - *(_data.begin()));
	throw Span::SpanEmptySetException();
};



Span::Span(const Span &span) : _data(span._data), _size(span._size){};

Span & Span::operator = (const Span &rhs){
	if (&rhs != this)
    {
		_data = rhs._data;
		_size = rhs._size; 
    }
	return (*this);
};

Span::Span( unsigned int n ) : _size(n) {};

Span::Span( void ) : _size(0){};

Span::~Span( void ){};