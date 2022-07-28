/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:07:57 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/28 05:31:32 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
# include "../includes/A.hpp"
# include "../includes/B.hpp"
# include "../includes/C.hpp"

Base * generate( void ){
	srand (time(NULL));
	int		random = rand () % 3;
	Base	*obj;

	if (random == 0){
		return new A();
	}
	if (random == 1){
		return new B();
	}
	if (random == 2){
		return new C();
	
	return NULL;
};

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Class *A found it" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Class *B found it" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Class *C found it" << std::endl;
}



int main(){
	Base *pointer = generate();
	identify(pointer);
	return (0);
	// random instance 
};