#include <iostream>
#include "../includes/Zombie.hpp"
std::string Zombie::get_name( void ){
     return (this->_name);
}

void Zombie::set_name( std::string name ){
	this->_name = name;
}

void Zombie::announce( void ){
    std::cout << this->_name << ": BraiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ){
    this->_name = "unnamed";
    printf("bertb\n");
};

Zombie::Zombie( std::string name) : _name(name){};

Zombie :: ~Zombie( void ){
    std::cout << this->_name << ": destroyed" << std::endl;
};
