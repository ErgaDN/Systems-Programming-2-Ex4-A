#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(const Point &location, int hitTarget, const std::string &name, int speed)
    : Character(location, hitTarget, name), _speed(speed) {}

void Ninja::move(const Character *enemy) {}
void Ninja::slash(Character *enemy) {}
std::string Ninja::print()
{
    return "N";
}
