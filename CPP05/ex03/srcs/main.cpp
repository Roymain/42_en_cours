/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/06 21:33:06 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main(){

	Bureaucrat macron = Bureaucrat("macron", 6);
	std::cout << "grade = " << macron.getGrade() << std::endl;

	Intern				fiston = Intern();
	Form*				formun;

	try 
	{
		formun = fiston.makeForm("Presidential Pardon For", "foufi");
	}
	catch(const std::exception& e)
	{
		return (1);
	}
	formun->beSigned(macron);
	macron.signForm(*formun);
	macron.executeForm(*formun);
	macron.plusGrade();
	macron.executeForm(*formun);
	
	delete formun;
	

	
	return (0);    
};
