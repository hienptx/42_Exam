#pragma once
#include "ASpell.hpp"

class ASpell;

class Fwoosh: public ASpell{
	public:
	Fwoosh():ASpell("Fwoosh", "fwooshed"){}
	~Fwoosh();
	ASpell* clone() const {
		return (new Fwoosh());
	}
};