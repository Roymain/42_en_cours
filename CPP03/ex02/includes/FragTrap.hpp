/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:17:09 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 00:25:34 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ClapTrap {

	public:
			void attack( const std::string& target );
            
			FragTrap(const FragTrap &FragTrap);

            FragTrap & operator = (const FragTrap &rhs);

			int	getHp();
            
            void highFivesGuys(void);
            
			FragTrap( void );
			FragTrap( std::string name );
			~FragTrap( void );
	
};

#endif