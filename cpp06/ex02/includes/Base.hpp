/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:03:17 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/13 18:59:51 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>


class Base {
		private : 

		public : 
					Base( void ){};
					virtual ~Base( void ){};
};

Base * generate( void );
void identify( Base * p );









#endif