/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 04:28:56 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 04:29:04 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define FORM_PRES "Presidential Pardon Form"
#define FORM_ROBO "Robotomy Request Form"
#define FORM_SHRU "Shrubbery Creation Form"

#define FORM_MAX 3

Intern::Intern()
{
	// std::cout << "[INTERN] Default constructor called" << std::endl;
	return;
}

Intern::~Intern()
{
	// std::cout << "[INTERN] Destructor called" << std::endl;
	return;
}

Intern::Intern(const Intern &intern)
{
	// std::cout << "[INTERN] Copy constructor called" << std::endl;
	*this = intern;
	return;
}

Intern &Intern::operator=(const Intern &intern)
{
	// std::cout << "[INTERN] Copy assignment operator called" << std::endl;
	(void)intern;
	return (*this);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
	Form* form = NULL;
	Form *(Intern::*arr_functions[])(const std::string &target) = {
		&Intern::MakePresidentialPardonForm,
		&Intern::MakeRobotomyRequestForm,
		&Intern::MakeShrubberyCreationForm
	};

    (formName == FORM_PRES) && (form = (this->*arr_functions[T_FORM_PRES])(target));
    (formName == FORM_ROBO) && (form = (this->*arr_functions[T_FORM_ROBO])(target));
    (formName == FORM_SHRU) && (form = (this->*arr_functions[T_FORM_SHRU])(target));

	form && std::cout << "Intern created a " << formName << std::endl;
	!form && std::cout << "You should fire this intern! " << formName << " never ever EVER existed!" << std::endl;

	return (form);
}

Form *Intern::MakePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::MakeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::MakeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}