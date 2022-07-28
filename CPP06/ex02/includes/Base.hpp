/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:03:17 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 05:29:50 by rcuminal         ###   ########.fr       */
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

// class A : public Base {
// 	public:
// 			A( void ){};
// 			~A( void ){};
// };

// class B : public Base {
// 	public:
// 			B( void ){};
// 			~B( void ){};
// };

// class C : public Base {
// 	public:
// 			C( void ){};
// 			~C( void ){};
// };


Base * generate( void );
void identify( Base * p );









#endif