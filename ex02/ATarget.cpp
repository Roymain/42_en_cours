#include <iostream>
#include <string>
#include "ATarget.hpp"

ATarget::ATarget( void ){};
		
const std::string& ATarget::getType( void ) const {
	return (_type);
};

void ATarget::setType( const std::string& type){
	this->_type = type;
};

ATarget::ATarget( const ATarget& rhs ){
	*this = rhs;
}
;

ATarget & ATarget::operator = ( const ATarget & rhs){
	_type = rhs._type;
	return (*this);
}

ATarget::ATarget( const std::string& type ) : _type(type){
};

ATarget::~ATarget( void ){
};

void	ATarget::getHitBySpell( const ASpell& spellito ) const{
	std::cout << _type << " has been " << spellito.getEffect() << "!" << std::endl;
};
	
