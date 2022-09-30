/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:37:21 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/30 02:13:20 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>

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

			class FormNotSignException : public std::exception
			{
				public:
					 char const* what() const throw ();
			};
			
			void		beSigned( const Bureaucrat &bureaucrat );
			bool		getBool( void ) const;
			std::string	getFormname( void ) const;

			virtual void executeAction() const = 0;
			
			void execute(Bureaucrat const & executor) const;
		//	Form(const Form &Form);
			Form & operator = (const Form &rhs);
		//	Form & operator << (const Form &rhs);
			Form( std::string name, unsigned int ntosign, unsigned int ntoexec );
			virtual ~Form( void );


};

			std::ostream & operator << (std::ostream & o, Form const & form);

#endif