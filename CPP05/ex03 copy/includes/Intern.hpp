/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 04:29:59 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 04:30:03 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# define MAX_OPTIONS 3

enum t_form {
	T_FORM_PRES,
	T_FORM_ROBO,
	T_FORM_SHRU
};

class Intern {

public:
	Intern();
	~Intern();
	Intern(const Intern &intern);
	Intern & operator= (const Intern &intern);

	Form* makeForm(const std::string &formName, const std::string &target);

private:
	Form* MakePresidentialPardonForm(const std::string &target);
	Form* MakeRobotomyRequestForm(const std::string &target);
	Form* MakeShrubberyCreationForm(const std::string &target);
};

#endif