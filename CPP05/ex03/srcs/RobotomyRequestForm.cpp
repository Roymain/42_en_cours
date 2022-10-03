/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:40:25 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 00:57:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

# define SIGN_GRADE 72
# define EXEC_GRADE 45
# define FORM_NAME "robotomyRequest"


std::string RobotomyRequestForm::getTarget() const {
	return (this->_target);
};

void RobotomyRequestForm::executeAction() const {
	std::srand(time(0));
	bool success = std::rand() % 2;

	std::cout << "BRrrBrrBrrrrrr" << std::endl;
	if (success)
		std::cout << getTarget() << " has been robotized" << std::endl;
	else
		std::cout << "Operation fail" << std::endl;
};



RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm) : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE){
	*this = robotomyRequestForm;
}

RobotomyRequestForm & RobotomyRequestForm::operator= (const RobotomyRequestForm &robotomyRequestForm){
	if (this != &robotomyRequestForm) {
		_target = robotomyRequestForm.getTarget();
	}
	return (*this);
};



RobotomyRequestForm::RobotomyRequestForm() : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("No specific target"){
	std::cout << "Default constructor called (RR)" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target){
	std::cout << "RR Constructor for " << target << " called" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor for " << this->_target << " called (RR)" << std::endl;
};