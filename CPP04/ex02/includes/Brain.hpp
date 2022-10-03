/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:36:30 by Romain            #+#    #+#             */
/*   Updated: 2022/10/03 05:50:27 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain{
	private:	
		std::string _ideas[100];
	public:
	
		std::string *getIdeas( void );
		
		Brain( const Brain &Brain );
		Brain & operator = ( const Brain &brain );
		
		Brain(void);
		~Brain(void);

};

#endif
