/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:58:12 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 02:05:02 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {
    
    private:
			std::string _name;
			Weapon 		&_weapon;
    public:

			void set_name( std::string name );
			void attack( void );		
        
            HumanA(  std::string name, Weapon &weapon );
            ~HumanA( void );
    
};

#endif