/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:50:05 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 04:01:30 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

int main(){
	Data data = {"string" , 1000};
	
	std::cout << data.num << data.str << std::endl;

	uintptr_t ptr;

	Data * dtptr;

	ptr = serialize(&data);

	dtptr = deserialize(ptr);

	std::cout << dtptr->num << std::endl;
	


	
	return (0);
};