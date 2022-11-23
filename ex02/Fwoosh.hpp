#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"


class ATarget;

class Fwoosh : public ASpell {

	public:

		Fwoosh( void );
	
		virtual ~Fwoosh( void );
		
		virtual ASpell* clone( void ) const;


};
