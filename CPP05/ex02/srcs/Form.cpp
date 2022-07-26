/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:37:16 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/25 23:55:00 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

char const* Form::GradeTooHighException::what() const throw() {
	return ("error, grade too high");
}

char const* Form::GradeTooLowException::what() const throw() {
	return ("error, garde too low");
}


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

std::string Form::getFormname(){
	return (this->_formname);
};


Form::Form(std::string name, unsigned int ntosign, unsigned int ntoexec): _formname(name), _signedd(false){
    std::cout << "form's constructor called for " << name << std::endl;
    try
	{
		if( ntosign > 150 || ntosign < 1 || ntoexec > 150 || ntoexec < 1)
			throw std::exception();
		else
			this->_ntosign = ntosign;
			this->_ntoexec = ntoexec;
	}
	catch(std::exception & e)
	{
		std::cout << "error wrong grade, minimum grade applied" << std::endl;
		this->_ntosign = 150;
		this->_ntoexec = 150;
	}
};

Form::~Form(){
	std::cout << "destructor called for " << this->_formname << std::endl;
};