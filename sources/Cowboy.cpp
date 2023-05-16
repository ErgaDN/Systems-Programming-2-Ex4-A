#include "Cowboy.hpp"

using namespace ariel;

// Cowboy::Cowboy(Point location, int hitTarget, std::string name, int ballsCount)
// : Character(location, hitTarget, name), _ballsCount(ballsCount) {}
Cowboy::Cowboy(const std::string &name, const Point &location)
    : Character(location, 110, name), _ballsCount(6) {}

void Cowboy::shoot(Character *enemy)
{
}
bool Cowboy::hasboolets() const
{
    return true;
}
void Cowboy::reload()
{
}

std::string Cowboy::print()
{
    return "C";
}

std::ostream &operator<<(std::ostream &os, const Cowboy &cowboy)
{
    return os;
}
