/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:26:58 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/13 22:41:10 by rcuminal         ###   ########.fr       */
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

			Zombie( void );
			Zombie( std::string name );
			~Zombie( void );
};

void randomChump( std::string name);
Zombie *newZombie( std::string name );

#endif