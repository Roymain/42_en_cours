/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/30 00:20:09 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(){



    Bureaucrat bribri = Bureaucrat("bribri", 151);
    Bureaucrat macron = Bureaucrat("macron", 123);
    std::cout << "grade = " << macron.getGrade() << std::endl;
    std::cout << "bribri grade = " << bribri.getGrade() << std::endl;
  
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    std::cout << "grade = " << macron.getGrade() << std::endl;
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    macron.minusGrade();
    //macron.minusGrade();

    
    return (0);    
};
