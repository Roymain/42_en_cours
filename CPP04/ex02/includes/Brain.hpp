/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:56:09 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/21 05:40:46 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain {
	private:
			std::string		_ideas[100];
			std::string		_name;
	public:
			Brain( std::string name );
			virtual ~Brain( void );
};

#endif