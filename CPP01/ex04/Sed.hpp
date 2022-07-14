/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:41:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 02:45:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#ifndef SED_HPP
# define SED_HPP

class Sed {

	private:
			std::string		s1;
			std::string		s2;
	public:
			


			Sed( std::string s1, std::string s2 );
			~Sed( void );
	
	
};

#endif