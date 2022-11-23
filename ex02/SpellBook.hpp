#pragma once

#include <vector>
#include "ASpell.hpp"

class SpellBook {
	private:
		std::vector<ASpell*>	_book;

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string& spell);
		ASpell* createSpell(const std::string& spell);

};