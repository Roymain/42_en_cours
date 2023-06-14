/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/06 20:17:36 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(){

//	Bureaucrat macron = Bureaucrat("macron", 6);
	Bureaucrat macron = Bureaucrat("macron", 73);
	std::cout << "grade = " << macron.getGrade() << std::endl;

//	PresidentialPardonForm form1 = PresidentialPardonForm("bribri");
	RobotomyRequestForm form1 = RobotomyRequestForm("bribri");
//	ShrubberyCreationForm form1 = ShrubberyCreationForm("bribri");

	try
	{
		form1.beSigned(macron);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		macron.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		macron.executeForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	macron.plusGrade();
	try
	{
		macron.executeForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << macron << std::endl;
	std::cout << form1 << std::endl;


	

	
	return (0);    
};
