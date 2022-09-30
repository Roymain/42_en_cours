/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:01:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/30 01:55:17 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include "Form.hpp"

class Form;

class Bureaucrat {
	
	private:
			const std::string		_name;
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

			void			signForm( Form & form);
			std::string		getName( void ) const ;
			unsigned int	getGrade( void ) const ;
			void			plusGrade( void );
			void			minusGrade( void );

			Bureaucrat(const Bureaucrat &Bureaucrat);
			Bureaucrat & operator = (const Bureaucrat &rhs);
			Bureaucrat & operator << (const Bureaucrat &rhs);
			
			Bureaucrat( void );
			Bureaucrat( std::string name, unsigned int grade );
			~Bureaucrat( void );
	
};

			std::ostream & operator << ( std::ostream & oper, Bureaucrat const & rhs );

#endif