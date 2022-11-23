#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected: 
		std::string _type;

		
	public:
				
		ATarget( void );
		ATarget( const ATarget& rhs );
		ATarget & operator = ( const ATarget & rhs);

		const std::string& getType( void ) const ;

		void setType( const std::string& type);

		ATarget( const std::string& type );
		virtual ~ATarget( void );
		
		virtual ATarget* clone( void ) const = 0;

		void	getHitBySpell( const ASpell& spellito ) const;

};
