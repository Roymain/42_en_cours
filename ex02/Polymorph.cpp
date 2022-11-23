#include <iostream>
#include <string>
#include "Polymorph.hpp"

Polymorph::Polymorph( void ) : ASpell("Polymorph", "Polymorphed") {};
		

Polymorph::~Polymorph( void ){
};

ASpell* Polymorph::clone() const {
	return ( new Polymorph());
};
