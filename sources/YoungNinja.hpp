#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
        public:
            // YoungNinja(Point location, int hitTarget, std::string name, int speed);
            YoungNinja(const std::string& name, const Point& location);
            ~YoungNinja();
    };    
}

#endif