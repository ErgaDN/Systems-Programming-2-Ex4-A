#ifndef POINT_HPP
#define POINT_HPP

namespace ariel
{
    class Point
    {
    private:
        double _x;
        double _y;
    public:
        // Point();
        Point(double x, double y);
        // ~Point();

        double getX() const { return _x; }
        double getY() const { return _y; }
        double distance(const Point& p) const;
        void print();
        Point moveTowards(const Point& source, const Point& dest, const double dis);
    };

}

#endif
// Point::Point(/* args */)
// {
// }

// Point::~Point()
// {
// }
