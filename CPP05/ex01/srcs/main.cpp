/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 05:27:12 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(){

	Bureaucrat macron = Bureaucrat("macron", 23);
	std::cout << "grade = " << macron.getGrade() << std::endl;

	Form formun = Form("bribri", 22, 100);
	
	try
	{
		formun.beSigned(macron);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	macron.signForm(formun);
	
	macron.plusGrade();
	try
	{
		formun.beSigned(macron);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	macron.signForm(formun);
	std::cout << macron;
	std::cout << formun;
	return (0);    
};
