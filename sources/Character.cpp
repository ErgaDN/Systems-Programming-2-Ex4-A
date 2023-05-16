#include "Character.hpp"

using namespace ariel;

    // Character::Character(int hitTarget) : _hitTarget(hitTarget){}

    Character::Character (const Point& location, int hitPoint, const std::string& name)
        : _location(location), _hitPoint(hitPoint), _name(name)
    {
    }

    Character::Character(const Character& other)
        : _location(other._location), _hitPoint(other._hitPoint), _name(other._name)
    {
    }

    
    bool Character::isAlive() const
    {
        return true;
    }
    double Character::distance(const Character &other) const
    {
        return 1.0;
    }
    void Character::hit(const int num) {}
    std::string Character::print()  
    {
        return "";
    }
