/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:26:58 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 00:00:50 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
  
  private:
          std::string _name;
  public:
			std::string get_name( void );
			
			void announce( void );
			
			void set_name( std::string );

			Zombie( std::string name );
			Zombie( void );
			~Zombie( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif