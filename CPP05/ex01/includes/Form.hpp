/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:37:21 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 00:35:05 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	
	private:
			const std::string _formname;
			bool			_signedd;
			
			unsigned int	_ntosign;
			unsigned int	_ntoexec;
			
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
			
			void		beSigned( const Bureaucrat &bureaucrat );
			bool		getBool( void );
			std::string	getFormname( void );
			

		//	Form(const Form &Form);
		//	Form & operator = (const Form &rhs);
		//	Form & operator << (const Form &rhs);
			Form( std::string name, unsigned int ntosign, unsigned int ntoexec );
			virtual ~Form( void );
};

#endif