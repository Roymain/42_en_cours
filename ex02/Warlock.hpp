#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
	private: 
		std::string _name;
		std::string _title;
		SpellBook	_book;

		Warlock( void );
		Warlock( const Warlock& rhs );
		Warlock & operator = ( const Warlock & rhs);
		
	public:
		const std::string& getName( void ) const ;
		const std::string& getTitle( void ) const ;

		void setTitle( const std::string& title);

		Warlock( const std::string& name, const std::string& title );
		~Warlock( void );
		
		void introduce() const;
		
		void learnSpell( ASpell* spell );
		void forgetSpell( std::string spell );
		void launchSpell( std::string spell, const ATarget& cible );

};			
