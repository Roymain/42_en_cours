/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:37:16 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 05:21:36 by rcuminal         ###   ########.fr       */
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
		if(bureaucrat.getGrade() > this->_ntosign)
			throw Form::GradeTooLowException();
		this->_signedd = true;
}

bool Form::getBool() const {
	return (this->_signedd);
};

std::string Form::getFormname() const {
	return (this->_formname);
};

unsigned int const Form::getNtosign() const {
	return (this->_ntosign);
}

unsigned int const Form::getNtoexec() const {
	return (this->_ntoexec);
}

std::ostream & operator << ( std::ostream & oper, Form const & rhs ){
	oper << rhs.getFormname() << ", sign :" << rhs.getNtosign() << " exec : " <<
	rhs.getNtoexec() << " signed : " << rhs.getBool() << "." << std::endl;
	return oper ;
};

Form::Form(std::string const name, unsigned int const ntosign, unsigned int const ntoexec):
_formname(name), _signedd(false), _ntosign(ntosign), _ntoexec(ntoexec){
    std::cout << "form's constructor called for " << name << std::endl;
		if( ntosign > 150 || ntoexec > 150 )
			throw Bureaucrat::GradeTooLowException();
		if( ntosign < 1 || ntoexec < 1 )
			throw Bureaucrat::GradeTooHighException();
};

Form::~Form(){
	std::cout << "destructor called for " << this->_formname << std::endl;
};