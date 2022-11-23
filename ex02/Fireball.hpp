#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"


class ATarget;

class Fireball : public ASpell {

	public:

		Fireball( void );
	
		virtual ~Fireball( void );
		
		virtual ASpell* clone( void ) const;


};
