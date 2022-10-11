/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:00:13 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/10 21:56:28 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>
# include <stack>

template <typename T> 
class MutantStack : public std::stack<T> {
	private:
			
	public:
			typedef typename std::stack<T>::container_type::iterator		iterator;
			typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

			MutantStack & operator = ( const MutantStack &rhs ){
				if (&rhs == this)
					return (*this);
				*(this->c) =(*(rhs.c));
				return (*this);
			}
			MutantStack( const MutantStack & rhs ) : std::stack<T>(rhs){};
			MutantStack(): std::stack<T>(){};
			~MutantStack(){};

			iterator begin() {
				return this->c.begin();
			}
			const_iterator begin() const {return this->c.begin();}

			iterator end() {
				return this->c.end();
			}
			const_iterator end() const {return this->c.end();}
};
