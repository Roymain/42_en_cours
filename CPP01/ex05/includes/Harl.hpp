/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:04:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 23:08:52 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef HARL_HPP
# define HARL_HPP

class Harl {

	private:
			void debug( void );
			void info( void );
			void warning( void );
			void error( void );
	
	public:
			void complain( std::string level );
			Harl( void );
			~Harl( void );
	
	
};

#endif