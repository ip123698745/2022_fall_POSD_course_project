#pragma once
#define _USE_MATH_DEFINES

#include "shape.h"
#include "two_dimensional_vector.h"

class Circle : public Shape
{
private:
    TwoDimensionalVector _radiusVec;

public:
    Circle(TwoDimensionalVector radiusVec):_radiusVec(radiusVec) {}
    ~Circle() {}

    double radius() const {
        return _radiusVec.length();
    }

    double area() const override {
        return radius() * radius() * M_PI;
    }

    double perimeter() const override {
        return 2 * radius() * M_PI;
    }

    string info() override {
        return "Circle (" + _radiusVec.info() + ")";
    }

    void addShape(Shape* shape) override {
        throw "Only compoundshape can add shape";
    }

    void deleteShape(Shape* shape) override {
        throw "Only compoundshape can delete shape";
    }

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator();
    }

    set<Point> getPoints() override {
        set<Point> points;
        double x, y;

        x = _radiusVec.a().x() + _radiusVec.length();
        y = _radiusVec.a().y() + _radiusVec.length();
        points.insert(Point(x,y));

        x = _radiusVec.a().x() - _radiusVec.length();
        y = _radiusVec.a().y() - _radiusVec.length();
        points.insert(Point(x,y));

        return points;
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCircle(this);
    }

    void move(double deltaX, double deltaY) override
    {
        _radiusVec.move(deltaX, deltaY);
    }
};