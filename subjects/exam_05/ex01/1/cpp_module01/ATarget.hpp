#pragma once
#include <iostream>
#include <string>

// Forward declaration only
class ASpell;

class ATarget {
protected:
    std::string _type;
    
public:
    ATarget(std::string type): _type(type) {}
    ATarget(): _type("") {}
    ATarget(const ATarget& other): _type(other._type) {}
    ATarget& operator=(const ATarget& other) {
        if (this != &other) {
            _type = other._type;
        }
        return *this;
    }
    virtual ~ATarget() {}
    
    std::string getType() const { return _type; }
    virtual ATarget* clone() const = 0;
    
    // Declaration only
    void getHitBySpell(const ASpell& spell) const;
};