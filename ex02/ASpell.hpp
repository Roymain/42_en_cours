#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected: 
		std::string _name;
		std::string _effect;

		
	public:
		ASpell( void );
		ASpell( const ASpell& rhs );
		ASpell & operator = ( const ASpell & rhs);
		const std::string& getName( void ) const ;
		const std::string& getEffect( void ) const ;

		void setEffect( const std::string& effect);

		ASpell( const std::string& name, const std::string& effect );
		virtual ~ASpell( void );
		
		virtual ASpell* clone( void ) const = 0;

		void launch( const ATarget& targetelito );

};	


