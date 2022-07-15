/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:17:51 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 21:46:19 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv){

	std::fstream file;
	std::string str;
	
	if (argc != 4){
		std::cout << "./progname s1 s2 file" << std::endl;
		return (1);
	}
	file.open(argv[3], std::fstream::in);
	if (!file.is_open()){
		std::cout << "File not found" << std::endl;
		return (1);
	}
	Sed Sed(argv[1], argv[2], argv[3]);
	
	while (!file.eof()){
		getline(file, str);
		Sed.replicator(str);
	}
	Sed.closing();
	file.close();


	return (0);
};