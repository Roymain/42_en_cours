#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"


class Dummy :  public ATarget {

	public:

		Dummy( void );
	
		virtual ~Dummy( void );
		
		virtual ATarget* clone( void ) const;


};
