#include "HumanB.hpp"

void HumanB::set_name( std::string name ){
	this->_name = name;
};

void HumanB::setWeapon( Weapon &Weapon ){
	this->_weapon = &Weapon;
};

void HumanB::attack( void ){
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " <<  this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack (no weapon)." << std::endl;
}

HumanB::HumanB( std::string name, Weapon &weapon ) : _name(name), _weapon(&weapon){
};

HumanB::HumanB( std::string name ) : _name(name){

};



HumanB::~HumanB( void ){};