/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:01:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 03:13:04 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <iostream>
#include <stdexcept>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"

class Form;

class Bureaucrat {
	
	private:
			std::string		_name;
			int	_grade;
	public:
	
			class GradeTooHighException : public std::exception
			{
				public:
					 char const* what() const throw ();
			};
			
			class GradeTooLowException : public std::exception
			{
				public:
					 char const* what() const throw ();
			};



			std::string		getName( void ) const ;
			unsigned int	getGrade( void ) const ;
			void			plusGrade( void );
			void			minusGrade( void );

			void signForm( Form &Form );

			void executeForm(Form const & form);
			

			Bureaucrat(const Bureaucrat &Bureaucrat);
			Bureaucrat & operator = (const Bureaucrat &rhs);
			Bureaucrat & operator << (const Bureaucrat &rhs);
			Bureaucrat( void );
			Bureaucrat( std::string name, unsigned int grade );
			~Bureaucrat( void );
	
};

			std::ostream & operator << ( std::ostream & oper, Bureaucrat const & rhs );

#endif