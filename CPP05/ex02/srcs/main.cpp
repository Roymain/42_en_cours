/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 01:36:24 by rcuminal         ###   ########.fr       */
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

//	PresidentialPardonForm formun = PresidentialPardonForm("bribri");
	RobotomyRequestForm formun = RobotomyRequestForm("bribri");
//	ShrubberyCreationForm formun = ShrubberyCreationForm("bribri");

	formun.beSigned(macron);
	macron.signForm(formun);
	macron.plusGrade();
	macron.plusGrade();
	std::cout << "grade = " << macron.getGrade() << std::endl;
	formun.beSigned(macron);
macron.signForm(formun);
	macron.executeForm(formun);
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.plusGrade();
	macron.executeForm(formun);

	

	
	return (0);    
};
