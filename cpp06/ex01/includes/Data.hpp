/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:28:30 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 03:38:09 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct Data {
	
	std::string str;

	int			num;
	
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif