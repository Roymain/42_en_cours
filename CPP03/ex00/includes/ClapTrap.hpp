/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:11:12 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/20 22:50:19 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap {
	
    private:
			std::string 	_name;
			int				_hp;
			int				_mana;
			int				_ad;
	public:
			void attack( const std::string& target );
			void takeDamage( unsigned int amount );
			void beRepaired( unsigned int amount );

			ClapTrap( void );
			ClapTrap( std::string name );
			~ClapTrap( void );
    
};

#endif