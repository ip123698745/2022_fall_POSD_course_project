#pragma once

#include <set>
#include <string>
#include "shape.h"

class BoundingBox
{
private:
    Point _max;
    Point _min;

public:
    BoundingBox(set<Point> points){
        if(points.empty())
        {
            throw "No point in set";
        }

        _max = calMaximumPoint(points);
        _min = calMinimumPoint(points);
    }

    Point calMaximumPoint(set<Point> points) {
        if(points.empty())
        {
            throw "No point in set";
        }

        double Max_X = (*points.begin()).x();
        double Max_Y = (*points.begin()).y();

        for(const Point p : points)
        {
            if(p.x() > Max_X)
            {
                Max_X = p.x();
            }

            if(p.y() > Max_Y)
            {
                Max_Y = p.y();
            }
        }

        return Point(Max_X, Max_Y);
    }

    Point calMinimumPoint(set<Point> points) {
        if(points.empty())
        {
            throw "No point in set";
        }

        double Min_X = (*points.begin()).x();
        double Min_Y = (*points.begin()).y();

        for(const Point p : points)
        {
            if(p.x() < Min_X)
            {
                Min_X = p.x();
            }

            if(p.y() < Min_Y)
            {
                Min_Y = p.y();
            }
        }

        return Point(Min_X, Min_Y);
    }

    Point max() {
        return _max;
    }

    Point min() {
        return _min;
    }

    bool collide(BoundingBox *box) {
        return !((this->max().x() < box->min().x()) || (this->min().x() > box->max().x()) 
            || (this->max().y() < box->min().y()) || (this->min().y() > box->max().y())); 
    }
};