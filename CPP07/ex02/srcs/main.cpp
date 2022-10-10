/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:07:40 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/09 23:39:33 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Array.hpp"


int main()
{
	Array<int> j(5);
	Array<std::string> list(2);

	list[0] = "test";
	list[1] = "plop";

	std::cout << "String array content : " << std::endl;
	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << "list[" << i << "] = " << list[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Copy list :" << std::endl;
	Array<std::string> listcopy(list);
	std::cout << "Change list[0] to \"murp\"" << std::endl;
	list[0] = "murp";
	std::cout << "Listcopy[0] = " << listcopy[0] << std::endl;
	std::cout << "List[0] = " << list[0] << std::endl;

	std::cout << std::endl;
	std::cout << "Int array content : " << std::endl;
	for (unsigned int i = 0; i < j.size(); i++)
		std::cout << "j" << i << " = " << j[i] << std::endl;

	std::cout << std::endl;
	Array<int> intassign = j;
	std::cout << "Int array content : " << std::endl;
	for (unsigned int i = 0; i < j.size(); i++)
		std::cout << "intassign[" << i << "] = " << intassign[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Modify value (previous + 1): " << std::endl;
	for (unsigned int i = 0; i < j.size(); i++)
		if (i != 0)
			intassign[i] = intassign[i - 1] + 1;
	for (unsigned int i = 0; i < j.size(); i++)
		std::cout << "intassign[" << i << "] = " << intassign[i] << std::endl;

	std::cout << std::endl;
	std::cout << "See out of the bound : " << std::endl;
	try
	{
		std::cout << "jx = " << j[j.size() + 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "Empty contructor : " << std::endl;
	Array<int> contr;
	try
	{
		std::cout << "contrLen = " << contr.size() << std::endl;
		std::cout << "contrx = " << contr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (size_t i = 0; i < j.size(); i++)
	{
		j[i] = rand();
		std::cout << j[i] << " " ;
	}
	std::cout << std::endl ;
	const Array<int> b(j);
	for (size_t i = 0; i < b.size(); i++)
	{
		//b[i] = 0;
		std::cout << b[i] << " " ;
	}
	const unsigned int	x = 5;
	const Array<int> xC(x);
	return 0;
}