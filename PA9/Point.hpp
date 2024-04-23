#pragma once
// a point class to make implementing the piece class easier

class Point
{
private:
    int x, y;
public:
    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};