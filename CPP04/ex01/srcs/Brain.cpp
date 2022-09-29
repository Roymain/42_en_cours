# include "../includes/Brain.hpp"


Brain::Brain(const Brain &brain){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
	return;
}

Brain &Brain::operator = (const Brain &brain){
	std::cout << "Brain copy operator called" << std::endl;
	if (&brain != this)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = brain._ideas[i];
	}
	return (*this);
}



Brain::Brain(void){
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Have no idea!";
	return ;
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
	return ;
}