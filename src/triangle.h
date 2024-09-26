#pragma once

#include "shape.h"
#include "two_dimensional_vector.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector _v1;
    TwoDimensionalVector _v2;

    double thirdSideLength() const{
        if((_v1.a()) == (_v2.a()))
        {
            return TwoDimensionalVector(_v1.b(), _v2.b()).length();
        }
        else if((_v1.a()) == (_v2.b()))
        {
            return TwoDimensionalVector(_v1.b(), _v2.a()).length();
        }
        else if((_v1.b()) == (_v2.a()))
        {
            return TwoDimensionalVector(_v1.a(), _v2.b()).length();
        }
        
        return TwoDimensionalVector(_v1.a(), _v2.a()).length();
    }

    bool isTriangle(TwoDimensionalVector v1, TwoDimensionalVector v2) const{
        return (((v1.a()) == (v2.a())) || ((v1.a()) == (v2.b())) || ((v1.b()) == (v2.a())) || ((v1.b()) == (v2.b())))
            && (abs(v1.cross(v2)) > 0.001);
    }
public:
    Triangle(TwoDimensionalVector v1, TwoDimensionalVector v2): _v1(v1), _v2(v2){
        if(!isTriangle(v1, v2))
        {
            throw "It's not a Triangle";
        }
    }
    ~Triangle() {}

    double area() const override {
        return abs(_v1.cross(_v2))/2;
    }

    double perimeter() const override {
        return thirdSideLength() + _v1.length() + _v2.length();
    }

    string info() override {
        return "Triangle (" + _v1.info() + ", " + _v2.info() + ")";
    }

    void addShape(Shape *shape) override {
        throw "Only compoundshape can add shape";
    }

    void deleteShape(Shape *shape) override {
        throw "Only compoundshape can delete shape";
    }

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator();
    }

    set<Point> getPoints() override {
        set<Point> pointSet{_v1.a(), _v1.b(), _v2.a(), _v2.b()};

        return pointSet;
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitTriangle(this);
    }
    
    void move(double deltaX, double deltaY) override
    {
        _v1.move(deltaX, deltaY);
        _v2.move(deltaX, deltaY);
    }
};