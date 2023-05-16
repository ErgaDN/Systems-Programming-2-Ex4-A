#include "Point.hpp"


using namespace ariel;
    
    Point::Point(double x, double y) : _x(x), _y(y) {}

    double Point::distance(const Point& p) const
    {
        return 1.0;
    }

    void Point::print() 
    {
        
    }

    Point Point::moveTowards(const Point& source, const Point& dest, const double dis)
    {
        return Point(1,1);
    }

