/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:07:40 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/09 23:15:23 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/iter.hpp"

#define TEST_LEN 22

int main()
{
	int	integer[TEST_LEN] = {0};
	::print_array(integer, TEST_LEN);
	::iter(integer, TEST_LEN, &(::acc));
	::print_array(integer, TEST_LEN);

	char	string[TEST_LEN] = "je pense donc je suis";
	::print_array(string, TEST_LEN);
	::iter(string, TEST_LEN, &(::acc));
	::print_array(string, TEST_LEN);




	const int	integer1[TEST_LEN] = {0};
	::print_array(integer1, TEST_LEN);
	// ::iter(integer1, TEST_LEN, &(::acc));
	::print_array(integer1, TEST_LEN);

	const char	string1[TEST_LEN] = "je pense donc je suis";
	::print_array(string1, TEST_LEN);
	//::iter(string1, TEST_LEN, &(::acc));
	::print_array(string1, TEST_LEN);
	
	return 0;
}