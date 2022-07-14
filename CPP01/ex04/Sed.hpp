/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:41:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 04:40:33 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#ifndef SED_HPP
# define SED_HPP

class Sed {

	private:
			std::string		_s1;
			std::string		_s2;
			std::fstream    _replaced;
	public:
			void replaceator( std::string line, size_t size );
			void replicator( std::string line );

			Sed( void );
			Sed( std::string s1, std::string s2, std::string replaced );
			~Sed( void );
	
	
};

#endif