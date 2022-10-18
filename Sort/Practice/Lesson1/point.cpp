#include <iostream>

using namespace std;

class Point
{
public:
    int x, y;

    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    ~Point()
    {
        this->x = 0;
        this->y = 0;
    }

    friend istream &operator>>(istream &is, Point p)
    {
        is >> p.x;
        is >> p.y;
    }

    friend ostream &operator<<(ostream &os, Point p)
    {
        os << p.x << " " << p.y;
    }
};