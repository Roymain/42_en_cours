/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:39:27 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 00:52:33 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>

# include "Form.hpp"


class Form;

class PresidentialPardonForm : public Form {

	private:
			std::string _target;
		
	public:
	
			void executeAction() const;
			std::string getTarget() const;
		
		
		    PresidentialPardonForm (const PresidentialPardonForm &presidentialPardonForm);
		    PresidentialPardonForm & operator= (const PresidentialPardonForm &presidentialPardonForm);
		
		
			PresidentialPardonForm( void );
		    PresidentialPardonForm (const std::string &target);
			~PresidentialPardonForm( void );
};

#endif