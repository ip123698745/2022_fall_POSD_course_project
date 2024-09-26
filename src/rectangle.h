#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector _lengthVec;
    TwoDimensionalVector _widthVec;

    bool isRectangle(TwoDimensionalVector lv, TwoDimensionalVector wv)
    {
        return (((lv.a()) == (wv.a())) || ((lv.a()) == (wv.b())) || ((lv.b()) == (wv.a())) || ((lv.b()) == (wv.b())))
            && (abs(lv.dot(wv)) < 0.001);
    }
public:
    Rectangle(TwoDimensionalVector lengthVec, TwoDimensionalVector widthVec): _lengthVec(lengthVec), _widthVec(widthVec){
        if(!isRectangle(lengthVec, widthVec))
        {
            throw "It's not a Rectangle";
        }
    }
    ~Rectangle() {}

    double length() const {
        return _lengthVec.length();
    }

    double width() const {
        return _widthVec.length();
    }

    double area() const override {
        return abs(_lengthVec.cross(_widthVec));
    }

    double perimeter() const override {
        return 2 * (length() + width());
    }

    string info() override {
        return "Rectangle (" + _lengthVec.info() + ", " + _widthVec.info() + ")";
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

        if((_lengthVec.a())==(_widthVec.a())){
            points.insert(_lengthVec.a());
            points.insert(_lengthVec.b());
            points.insert(_widthVec.b());

            x = _lengthVec.b().x() + _widthVec.b().x() - _lengthVec.a().x();
            y = _lengthVec.b().y() + _widthVec.b().y() - _lengthVec.a().y();
        }
        else if((_lengthVec.a())==(_widthVec.b())){
            points.insert(_lengthVec.a());
            points.insert(_lengthVec.b());
            points.insert(_widthVec.a());

            x = _lengthVec.b().x() + _widthVec.a().x() - _lengthVec.a().x();
            y = _lengthVec.b().y() + _widthVec.a().y() - _lengthVec.a().y();
        }
        else if((_lengthVec.b())==(_widthVec.a())){
            points.insert(_lengthVec.b());
            points.insert(_lengthVec.a());
            points.insert(_widthVec.b());

            x = _lengthVec.a().x() + _widthVec.b().x() - _lengthVec.b().x();
            y = _lengthVec.a().y() + _widthVec.b().y() - _lengthVec.b().y();
        }
        else if((_lengthVec.b())==(_widthVec.b())){
            points.insert(_lengthVec.b());
            points.insert(_lengthVec.a());
            points.insert(_widthVec.a());

            x = _lengthVec.a().x() + _widthVec.a().x() - _lengthVec.b().x();
            y = _lengthVec.a().y() + _widthVec.a().y() - _lengthVec.b().y();
        }

        points.insert(Point(x, y));

        return points;
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitRectangle(this);
    }

    void move(double deltaX, double deltaY) override
    {
        _lengthVec.move(deltaX, deltaY);
        _widthVec.move(deltaX, deltaY);
    }
};