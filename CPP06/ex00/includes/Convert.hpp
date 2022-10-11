/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:03:19 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/10 21:52:30 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Convert {
			private:
					std::string _arg;
					
			public:

			void	toChar( void );
			void	toInt( void );
			void	toFloat( void );
			void	toDouble( void );

			Convert & operator = ( const Convert & rhs);
			Convert( const Convert & rhs);
			Convert();
			Convert( char *arg );
			~Convert( void );
					
	
};

#endif