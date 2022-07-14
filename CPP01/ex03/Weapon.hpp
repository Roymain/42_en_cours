/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:24:10 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 00:56:01 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {
    
    private:
			std::string _type;

	public:
			const std::string& getType( void ) const;
			void setType(std::string );

			Weapon(std::string type);
			~Weapon();
    
};

#endif