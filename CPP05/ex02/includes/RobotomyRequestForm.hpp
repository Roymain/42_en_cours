/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:37:43 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/26 00:38:40 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>

# include "Form.hpp"


class Form;

class RobotomyRequestForm : public Form {

private:
	std::string _target;
	
public:

	void executeAction() const;
	std::string getTarget() const;

    
    RobotomyRequestForm (const RobotomyRequestForm &RobotomyRequestForm);
    RobotomyRequestForm (const std::string &target);
    RobotomyRequestForm & operator= (const RobotomyRequestForm &RobotomyRequestForm);


	RobotomyRequestForm();
	~RobotomyRequestForm();
};

#endif