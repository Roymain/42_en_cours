/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:40:30 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 03:10:24 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

# define SIGN_GRADE 145
# define EXEC_GRADE 137
# define FORM_NAME "shrubberyCreation"

ShrubberyCreationForm::ShrubberyCreationForm() : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("No specific target"){
	std::cout << "Default constructor called (SC)" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target){
	std::cout << "Constructor for " << target << " called" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor for " << this->_target << " called (SC)" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) : Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE){
	*this = shrubberyCreationForm;

};

ShrubberyCreationForm & ShrubberyCreationForm::operator= (const ShrubberyCreationForm &shrubberyCreationForm){
	if (this != &shrubberyCreationForm) {
		_target = shrubberyCreationForm.getTarget();
	}
	return (*this);
};

std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
};

void ShrubberyCreationForm::executeAction() const {
	std::string fileName = getTarget() + "_shrubbery";
	std::ofstream shrubberyFile (fileName.c_str());

	shrubberyFile
	<< "                                              ." << std::endl
	<< "                                   .         ;" << std::endl
	<< "      .              .              ;%     ;;" << std::endl
	<< "        ,           ,                :;%  %;" << std::endl
	<< "         :         ;                   :;%;'     .," << std::endl
	<< ",.        %;     %;            ;        %;'    ,;" << std::endl
	<< "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
	<< "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl
	<< "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
	<< "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
	<< "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
	<< "         `:%;.  :;bd%;          %;@%;'" << std::endl
	<< "           `@%:.  :;%.         ;@@%;'" << std::endl
	<< "             `@%.  `;@%.      ;@@%;" << std::endl
	<< "               `@%%. `@%%    ;@@%;" << std::endl
	<< "                 ;@%. :@%%  %@@%;" << std::endl
	<< "                   %@bd%%%bd%%:;" << std::endl
	<< "                     #@%%%%%:;;" << std::endl
	<< "                     %@@%%%::;" << std::endl
	<< "                     %@@@%(o);  . '" << std::endl
	<< "                     %@@@o%;:(.,'" << std::endl
	<< "                 `.. %@@@o%::;" << std::endl
	<< "                    `)@@@o%::;" << std::endl
	<< "                     %@@(o)::;" << std::endl
	<< "                    .%@@@@%::;" << std::endl
	<< "                    ;%@@@@%::;." << std::endl
	<< "                   ;%@@@@%%:;;;." << std::endl
	<< "               ...;%@@@@@%%:;;;;,.." << std::endl;
	shrubberyFile.close();

};
