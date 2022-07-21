/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:08:01 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/15 23:30:02 by rcuminal         ###   ########.fr       */
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
			Fixed operator + (const Fixed  &fixed) const;
			Fixed operator - (const Fixed  &fixed) const;
			Fixed operator * (const Fixed  &fixed) const;
			Fixed operator / (const Fixed  &fixed) const;
			
			bool operator == (const Fixed  &fixed);
			bool operator != (const Fixed  &fixed);
			bool operator < (const Fixed  &fixed);
			bool operator <= (const Fixed  &fixed);
			bool operator > (const Fixed  &fixed);
			bool operator >= (const Fixed  &fixed);

			Fixed & operator ++ ( void );
			Fixed operator ++ ( int value );
			Fixed & operator -- ( void );
			Fixed operator -- ( int value );

			
			static Fixed & max(Fixed &lhs, Fixed &rhs);
			static const Fixed & max(const Fixed &lhs, const Fixed &rhs);
			static Fixed & min(Fixed &lhs, Fixed &rhs);
			static const Fixed & min(const Fixed &lhs, const Fixed &rhs);

			float toFloat( void ) const;
			int toInt( void ) const;
			
			Fixed( void );
			Fixed( const int value );
			Fixed( const float value );
			~Fixed( void );
};

std::ostream & operator << ( std::ostream & oper, Fixed const & rhs ); 

#endif