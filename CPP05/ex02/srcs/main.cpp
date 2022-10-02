/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/02 23:50:43 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(){

	Bureaucrat macron = Bureaucrat("macron", 6);
	std::cout << "grade = " << macron.getGrade() << std::endl;

	PresidentialPardonForm formun = PresidentialPardonForm("bribri");
	
	macron.signForm(formun);
	formun.beSigned(macron);
	macron.executeForm(formun);
	macron.plusGrade();
	macron.executeForm(formun);

	
	return (0);    
};
