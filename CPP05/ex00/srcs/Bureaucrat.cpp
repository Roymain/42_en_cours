/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:09:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/06 19:24:20 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"


void Bureaucrat::minusGrade( void ){

		if(this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	

};

void Bureaucrat::plusGrade( void ){

		if(this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;

};

unsigned int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}

std::ostream & operator << ( std::ostream & oper, Bureaucrat const & rhs ){
	oper << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return oper ;
};



char const* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("error, too high");
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("error, too low");
}









Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat) : _name(Bureaucrat._name) {
	*this = Bureaucrat;
	return;
};

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &rhs){
	if (&rhs != this)
		_grade = rhs._grade;
	return (*this);
};



Bureaucrat::Bureaucrat( std::string name, unsigned int grade ) : _name(name) {
	std::cout << "bureaucrat constructor called for " << name << std::endl;

		if(grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if(grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
};

Bureaucrat::Bureaucrat(){
	std::cout << "bureaucrat basic constructor called" << std::endl;
};

Bureaucrat::~Bureaucrat(){
	std::cout << "bureaucrat destructor called" << std::endl;
};