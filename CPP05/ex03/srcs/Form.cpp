/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:37:16 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 01:56:49 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

char const* Form::GradeTooHighException::what() const throw() {
	return ("error, grade too high");
}

char const* Form::GradeTooLowException::what() const throw() {
	return ("error, garde too low");
}

char const* Form::FormNotSignException::what() const throw() {
	return ("error, form not signed");
};

void Form::execute(Bureaucrat const & executor) const {
	
		if (executor.getGrade() > this->_ntoexec)
			throw Form::GradeTooLowException();
		else if (this->_signedd == false)
			throw Form::FormNotSignException();
		else 
		{
			std::cout << executor.getName() << " execute " << this->_formname << std::endl;
			executeAction();
		}

};

void Form::beSigned( const Bureaucrat & bureaucrat ){
	try
	{
		if(bureaucrat.getGrade() > this->_ntosign)
			throw Form::GradeTooLowException();
		this->_signedd = true;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

bool Form::getBool(){
	return (this->_signedd);
};

std::string Form::getFormname() const{
	return (this->_formname);
};


Form::Form(std::string name, unsigned int ntosign, unsigned int ntoexec): _formname(name), _signedd(false){
    std::cout << "form's constructor called : " << name << std::endl;
    try
	{
		if( ntosign > 150 || ntoexec > 150 )
			throw Bureaucrat::GradeTooLowException();
		if( ntosign < 1 || ntoexec < 1 )
			throw Bureaucrat::GradeTooHighException();
		else
			this->_ntosign = ntosign;
			this->_ntoexec = ntoexec;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
		this->_ntosign = 150;
		this->_ntoexec = 150;
	}
};

Form::~Form(){
	std::cout << "Form destructor called for " << this->_formname << std::endl;
};