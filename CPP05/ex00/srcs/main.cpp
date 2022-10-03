/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:48:44 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/03 05:02:21 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(){

    try
    {
        Bureaucrat err1 = Bureaucrat("min", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat err2 = Bureaucrat("max", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat bribri = Bureaucrat("bribri", 150);
    Bureaucrat macron = Bureaucrat("macron", 123);
    std::cout << "grade = " << macron.getGrade() << std::endl;
    std::cout << "bribri grade = " << bribri.getGrade() << std::endl;
    std::cout << macron << std::endl;
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
