/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:40:22 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/02 23:50:22 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

# define SIGN_GRADE 25
# define EXEC_GRADE 5
# define FORM_NAME "presidentialPardon"

PresidentialPardonForm::PresidentialPardonForm() : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("No specific target"){
	std::cout << "Default constructor called (PP)" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target){
	std::cout << "PP Constructor for " << target << " called" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor for " << this->_target << " called (PP)" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm) : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE){
	*this = presidentialPardonForm;
	return;
};

PresidentialPardonForm & PresidentialPardonForm::operator= (const PresidentialPardonForm &presidentialPardonForm){
	if (this != &presidentialPardonForm) {
		_target = presidentialPardonForm.getTarget();
	}
	return (*this);
};

std::string PresidentialPardonForm::getTarget() const {
	return (this->_target);
};

void PresidentialPardonForm::executeAction() const {
	std::cout << getTarget() << " has been pardoned by Zaphotruc!" << std::endl;
};