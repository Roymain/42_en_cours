#include <iostream>
#include <string>
#include "Dummy.hpp"

Dummy::Dummy( void ) : ATarget("Target Practice Dummy") {};
		

Dummy::~Dummy( void ){
};

ATarget* Dummy::clone() const{
	return ( new Dummy());
};		
