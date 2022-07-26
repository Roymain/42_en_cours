/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:36:41 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 03:14:45 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>

# include "Form.hpp"


class Form;

class ShrubberyCreationForm : public Form {

private:
	std::string _target;
	
public:

	void executeAction() const;
	std::string getTarget() const;

    
    ShrubberyCreationForm (const ShrubberyCreationForm &ShrubberyCreationForm);
    ShrubberyCreationForm (const std::string &target);
    ShrubberyCreationForm & operator= (const ShrubberyCreationForm &ShrubberyCreationForm);
	
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
};

#endif