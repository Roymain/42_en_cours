/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:08:01 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/15 05:43:37 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	private:
			int		_value;
			static const int _fractiobits = 8;
	public:
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			
			Fixed( Fixed const &copy );
			Fixed & operator = (const Fixed  &fixed);

			float toFloat( void ) const;
			int toInt( void ) const;
			
			Fixed( void );
			Fixed( const int value );
			Fixed( const float value );
			~Fixed( void );
};

std::ostream & operator << ( std::ostream & oper, Fixed const & rhs ); 

#endif