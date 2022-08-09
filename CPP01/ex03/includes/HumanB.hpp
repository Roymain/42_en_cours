/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:59:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 02:11:18 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {
    
    private:
			std::string _name;
			Weapon 		*_weapon;
    public:

			void set_name( std::string name );
			void setWeapon( Weapon &weapon );
			void attack( void );
			
        	HumanB(  std::string name );
            HumanB(  std::string name, Weapon &weapon );
            ~HumanB( void );
    
};

#endif