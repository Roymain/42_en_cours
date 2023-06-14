/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:09:53 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 05:37:27 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void Bureaucrat::executeForm(const Form  & form){
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getFormname() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

};


void	Bureaucrat::signForm( Form & form){
	if(form.getBool() == true)
		std::cout << this->_name << " signed " << form.getFormname() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getFormname() << " because his grade was too low." << std::endl;
};

void Bureaucrat::minusGrade( void ){
	try
	{
		if(this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
};

void Bureaucrat::plusGrade( void ){
	try
	{
		if(this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
};

unsigned int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}






char const* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("error, too high");
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("error, too low");
}








std::ostream & operator << ( std::ostream & oper, Bureaucrat const & rhs ){
	oper << rhs.getGrade();
	return oper ;
};

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat){
	*this = Bureaucrat;
	return;
};

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &rhs){
		if (&rhs != this)
		_grade = rhs._grade;
	return (*this);
};


Bureaucrat::Bureaucrat( std::string name, unsigned int grade ): _name(name) {    // : _name(name), _grade(grade) 
	std::cout << "bureaucrat constructor called for " << name << std::endl;
	try
	{
		if(grade < 1)
		{
			this->_grade = 150;
			throw Bureaucrat::GradeTooHighException();
		}
		else if(grade > 150)
		{
			this->_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		else
			this->_grade = grade;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
};

Bureaucrat::Bureaucrat(){
	std::cout << "bureaucrat basic constructor called" << std::endl;
};

Bureaucrat::~Bureaucrat(){
	std::cout << "bureaucrat destructor called" << std::endl;
};