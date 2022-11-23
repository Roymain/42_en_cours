#include <iostream>
#include <string>
#include "Warlock.hpp"

Warlock::Warlock( void ){};
		
const std::string& Warlock::getName( void ) const {
	return (_name);
};
const std::string& Warlock::getTitle( void ) const {
	return (_title);
};

void Warlock::setTitle( const std::string& title){
	this->_title = title;
};

Warlock::Warlock( const Warlock& rhs ){
	*this = rhs;
}
;

Warlock & Warlock::operator = ( const Warlock & rhs){
	_name = rhs._name;
	_title = rhs._title;
	return (*this);
}

Warlock::Warlock( const std::string& name, const std::string& title ) : _name(name), _title(title){
	std::cout << _name << ": This looks like another boring day." << std::endl;
};

Warlock::~Warlock( void ){
	std::cout << _name << ": My job here is done!\n";
		
};

void Warlock::introduce() const{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
};

void Warlock::learnSpell( ASpell* spell ){
	_book.learnSpell(spell);
};

void Warlock::forgetSpell( std::string spell ){
	_book.forgetSpell(spell);
};

void Warlock::launchSpell( std::string spell, const ATarget& cible ){
	ASpell* tmp = _book.createSpell(spell);
	tmp->launch(cible);
};
	
