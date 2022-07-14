/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:17:51 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 02:59:41 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv){

	std::fstream file;
	
	if (argc != 4){
		std::cout << "progname s1 s2 file" << std::endl;
		return (1);
	}
	file.open("test.txt");
	if (file.is_open()){
		std::cout << "File not found" << std::endl;
		return (1);
	}
	
	


	file.close();


	return (0);  
};