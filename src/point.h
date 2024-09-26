#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

class Point
{
private:
    double _x;
    double _y;

    string dtos(double num){
        stringstream sstream;
        double value = floor(num * 100 + .5) / 100;

        sstream << fixed << setprecision(2) << value;
        return sstream.str();
    }

public:
    Point(double x = 0, double y = 0): _x(x), _y(y){}
    ~Point() {}

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    bool operator==(const Point &pt) const {
        return (abs(_x - pt.x()) < 0.001) && (abs(_y - pt.y()) < 0.001);
    }

    bool operator<(const Point &pt) const{
        return _x < pt.x() || (_x == pt.x() && _y < pt.y());
    }

    void move(double deltaX, double deltaY)
    {
        _x += deltaX;
        _y += deltaY;
    }

    string info() {
        return "(" + dtos(_x) + ", " + dtos(_y) + ")";
    }
};