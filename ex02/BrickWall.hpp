#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"


class BrickWall :  public ATarget {

	public:

		BrickWall( void );
	
		virtual ~BrickWall( void );
		
		virtual ATarget* clone( void ) const;


};
