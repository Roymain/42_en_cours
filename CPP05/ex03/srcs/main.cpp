/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 01:53:40 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(){

	Bureaucrat macron = Bureaucrat("macron", 6);
//	Bureaucrat macron = Bureaucrat("macron", 73);

//	PresidentialPardonForm formun = PresidentialPardonForm("bribri");
	Intern				fiston = Intern();
	Form*				formun;

	std::cout << "grade = " << macron.getGrade() << std::endl;
	formun = fiston.makeForm("Presidential Pardon Form", "foufi");
	
	formun->beSigned(macron);
	macron.signForm(*formun);
	macron.executeForm(*formun);
	macron.plusGrade();
	macron.executeForm(*formun);
	
	
	
//	ShrubberyCreationForm formun = ShrubberyCreationForm("bribri");





	
	return (0);    
};
