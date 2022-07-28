/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:03:19 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 02:45:25 by rcuminal         ###   ########.fr       */
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

			Convert( char *arg );
			~Convert( void );
					
	
};

#endif