#include <iostream>
#include <string>
#include "ASpell.hpp"

ASpell::ASpell( void ){};
		
const std::string& ASpell::getName( void ) const {
	return (_name);
};
const std::string& ASpell::getEffect( void ) const {
	return (_effect);
};

void ASpell::setEffect( const std::string& effect){
	this->_effect = effect;
};

ASpell::ASpell( const ASpell& rhs ){
	*this = rhs;
}
;

ASpell & ASpell::operator = ( const ASpell & rhs){
	_name = rhs._name;
	_effect = rhs._effect;
	return (*this);
}

ASpell::ASpell( const std::string& name, const std::string& effect ) : _name(name), _effect(effect){
};

ASpell::~ASpell( void ){
};

void ASpell::launch( const ATarget& targetelito ){
	targetelito.getHitBySpell(*this);
};

