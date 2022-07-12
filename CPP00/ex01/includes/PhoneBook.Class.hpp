/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:52:32 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/12 03:14:14 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
#include <iostream>


class Phonebook {
   
    private:
            Contact _Contact[8];
			
            std::string _line;
            std::string ft_getline( void );
			
            int _incrementeur;
            
            void ft_add( void );
            void ft_firstname( void );
            void ft_lastname( void );
            void ft_nickname( void );
            void ft_phonenumber( void );
            void ft_search( void );
			void ft_printsearch( int index);
    
    public:
            void run();

            Phonebook( void );
            ~Phonebook( void );

};

#endif