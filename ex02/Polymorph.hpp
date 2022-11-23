#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"


class ATarget;

class Polymorph : public ASpell {

	public:

		Polymorph( void );
	
		virtual ~Polymorph( void );
		
		virtual ASpell* clone( void ) const;


};
