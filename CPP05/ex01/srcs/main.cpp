/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/02 23:11:38 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(){

	Bureaucrat macron = Bureaucrat("macron", 23);
	std::cout << "grade = " << macron.getGrade() << std::endl;

	Form formun = Form("bribri", 22, 100);
	
	formun.beSigned(macron);
	macron.signForm(formun);
	macron.plusGrade();
	formun.beSigned(macron);
	macron.signForm(formun);
	
	return (0);    
};
