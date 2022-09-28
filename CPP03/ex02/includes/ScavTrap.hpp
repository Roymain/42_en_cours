/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:05:47 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 00:16:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
	
	private:
			bool _odor;
	public:
			void attack( const std::string& target );
			void	guardGate();

			ScavTrap(const ScavTrap &ScavTrap);

ScavTrap & operator = (const ScavTrap &rhs);

			int	getHp();

			ScavTrap( void );
			ScavTrap( std::string name );
			~ScavTrap( void );
	
};

#endif