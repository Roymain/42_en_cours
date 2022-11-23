#include "SpellBook.hpp"


SpellBook::SpellBook(){};
SpellBook::~SpellBook(){
	for (std::vector<ASpell*>::iterator it = _book.begin(); it != _book.end(); it++){
			delete (*it);
		}
};

void SpellBook::learnSpell(ASpell* spell){
    _book.push_back(spell->clone());
};



void SpellBook::forgetSpell(const std::string& spell){
    if (_book.begin() != _book.end()){
	for (std::vector<ASpell*>::iterator it = _book.begin(); it != _book.end(); it++){
		if ((*it)->getName() == spell){
			delete *it;
			_book.erase(it);
			return;
		}
	}}
};



ASpell* SpellBook::createSpell(const std::string& spell){
	for (std::vector<ASpell*>::iterator it = _book.begin(); it != _book.end(); it++){
		if ((*it)->getName() == spell)
			return (*it);
	}
    return NULL;
};
