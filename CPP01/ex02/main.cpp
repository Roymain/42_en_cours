/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:06:15 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/14 00:18:52 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string A = "HI THIS IS BRAIN";
    std::string *stringPTR = &A;
    std::string &stringREF = A;
    
    std::cout << "The memory address of the string variable is " << &A << std::endl; 
    std::cout << "The memory address held by stringPTR is  " << stringPTR << std::endl; 
    std::cout << "The memory address held by stringREF is  " << &stringREF << std::endl;

    std::cout << "The value of the string variable is " << A << std::endl;
    std::cout << "The value pointed by stringPTR is " << *stringPTR << std::endl;
    std::cout << "The value pointed by stringREF is " << stringREF << std::endl;
  
}