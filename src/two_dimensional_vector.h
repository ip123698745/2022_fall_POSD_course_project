#pragma once

#include "point.h"

class TwoDimensionalVector
{
private:
    Point _a;
    Point _b;

public:
    TwoDimensionalVector(Point a, Point b): _a(a), _b(b){}
    ~TwoDimensionalVector() {}

    Point a() const {
        return _a;
    }

    Point b() const {
        return _b;
    }

    double length() const {
        return sqrt((_b.x() - _a.x()) * (_b.x() - _a.x()) + (_b.y() - _a.y()) * (_b.y() - _a.y()));
    }

    double dot(const TwoDimensionalVector vec) const {
        return (_b.x() - _a.x()) * (vec.b().x() - vec.a().x()) + (_b.y() - _a.y()) * (vec.b().y() - vec.a().y());
    }

    double cross(const TwoDimensionalVector vec) const {
        return (_b.x() - _a.x()) * (vec.b().y() - vec.a().y()) - (_b.y() - _a.y()) * (vec.b().x() - vec.a().x());
    }

    void move(double deltaX, double deltaY)
    {
        _a.move(deltaX, deltaY);
        _b.move(deltaX, deltaY);
    }

    string info() {
        return "Vector (" + _a.info() + ", " + _b.info() + ")";
    }
};