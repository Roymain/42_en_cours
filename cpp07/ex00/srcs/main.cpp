/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:44:37 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/09 22:54:59 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/whatever.hpp"

int main( void ) {
    {
        int a = 2;
        int b = 3;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        std::cout << "c = " << c << ", d = " << d << std::endl;
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        std::string	e = ::min(c, d);
        std::cout << "e = " << e << std::endl;
        e = "yolo";
        std::cout << "e = " << e << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    {
        const int a = 2;
        const int b = 3;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        std::string	e = ::min(c, d);
        std::cout << "e = " << e << std::endl;
        e = "yolo";
        std::cout << "e = " << e << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    }
	return 0;
}