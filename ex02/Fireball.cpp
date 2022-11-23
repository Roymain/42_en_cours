#include <iostream>
#include <string>
#include "Fireball.hpp"

Fireball::Fireball( void ) : ASpell("Fireball", "Fireballed") {};
		

Fireball::~Fireball( void ){
};

ASpell* Fireball::clone() const {
	return ( new Fireball());
};
