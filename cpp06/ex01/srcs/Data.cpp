/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:32:36 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 04:01:18 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

uintptr_t	serialize(Data* ptr){
	uintptr_t pter;

	pter = reinterpret_cast<uintptr_t>(ptr);
	return (pter);
};


Data*		deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
};