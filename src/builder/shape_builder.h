#pragma once

#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include <vector>
#include <stack>

class ShapeBuilder{
private:
    vector<Shape *> _result;
    stack<Shape *> topCompound;
public:
    void buildCircle(Point center, Point to_radius) {
        Shape *circle = new Circle(TwoDimensionalVector(center, to_radius));

        if(!topCompound.empty()){
            topCompound.top()->addShape(circle);
        }
        else{
            _result.push_back(circle);
        }
    }

    void buildTriangle(Point common_point, Point v1_point, Point v2_point) {
        Shape *triangle = new Triangle(
            TwoDimensionalVector(common_point, v1_point),
            TwoDimensionalVector(common_point, v2_point)
        );

        if(!topCompound.empty()){
            topCompound.top()->addShape(triangle);
        }
        else{
            _result.push_back(triangle);
        }
    }

    void buildRectangle(Point common_point, Point v1_point, Point v2_point) {
        Shape *rectangle = new Rectangle(
            TwoDimensionalVector(common_point, v1_point),
            TwoDimensionalVector(common_point, v2_point)
        );

        if(!topCompound.empty()){
            topCompound.top()->addShape(rectangle);
        }
        else{
            _result.push_back(rectangle);
        }
    }

    void buildCompoundShape() {
        topCompound.push(new CompoundShape());
    }

    void buildCompoundEnd() {
        Shape *tc = topCompound.top();
        topCompound.pop();

        if(topCompound.empty()){
            _result.push_back(tc);
        }
        else{
            topCompound.top()->addShape(tc);
        }
    }

    vector<Shape *> getResult() {
        return _result;
    }
};