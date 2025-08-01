#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell{
	protected:
		std::string _name;
		std::string _effects;
		ASpell();
		ASpell(const ASpell& other);
		ASpell& operator=(const ASpell& other);
	
	public:
		ASpell(std::string name, std::string effects): _name(name), _effects(effects){}

		std::string getName()const {return _name;}
		std::string getEffects()const {return _effects;}
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& target) const{
			target.getHitBySpell(*this);
		}
};