/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:25:12 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/12 03:14:31 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact {
  
  private:
          std::string _first_name;
          std::string _last_name;
          std::string _nickname;
          std::string _phonenumber;
  public:
			std::string get_firstname( void );
			std::string get_lastname( void );
			std::string get_nickname( void );
			std::string get_phonenumber( void );
			
			void set_firstname( std::string );
			void set_lastname( std::string );
			void set_nickname( std::string );
			void set_phonenumber( std::string );

			bool present( void );
			
			Contact( void );
			~Contact( void );
};

#endif