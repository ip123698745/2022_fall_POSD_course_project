#pragma once

#include "shape.h"

#include <list>
#include <algorithm>

class CompoundShape : public Shape
{
private:
    list<Shape *> _shapes;

public:
    CompoundShape() {}

    CompoundShape(Shape **shapes, int size) 
        :_shapes(shapes, shapes+size){}

    ~CompoundShape() {
        for(Shape *shape: _shapes){
            if(shape != nullptr){
                delete shape;
            }
        }
    }

    double area() const override {
        double area = 0;

        for(Shape *s: _shapes)
        {
            area += s->area();
        }

        return area;
    }

    double perimeter() const override {
        double p = 0;

        for(Shape *s: _shapes)
        {
            p += s->perimeter();
        }

        return p;
    }

    string info() override {
        string info = "CompoundShape (";

        for(list<Shape *>::iterator it = _shapes.begin(); it != _shapes.end();)
        {
            info += (*it)->info();

            if(++it != _shapes.end())
            {
                info += ", ";
            }
        }

        return info + ")";
    }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {

        if(find(_shapes.begin(),_shapes.end(),shape) != _shapes.end()){
            _shapes.remove(shape);
            delete shape;
        }
        
        for(Shape* s: _shapes){
            Iterator *it = s->createIterator(IteratorFactory::getInstance("DFS"));

            if(!it->isDone())
            {
                s->deleteShape(shape);
            }
            delete it;
        }
    }

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator(_shapes.begin(), _shapes.end());
    }

    set<Point> getPoints() override {
        set<Point> points;
        set<Point> temp;
        Iterator *csit = this->createIterator(IteratorFactory::getInstance("DFS"));

        for(; !csit->isDone(); csit->next())
        {
            Iterator *it = csit->currentItem()->createIterator(IteratorFactory::getInstance("DFS"));
            if(it->isDone())
            {
                temp = csit->currentItem()->getPoints();

                for(Point p : temp)
                {
                    points.insert(p);
                }
            }
            delete it;
        }

        delete csit;
        return points;
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCompoundShape(this);
    }

    void move(double deltaX, double deltaY) override
    {
        for (std::list<Shape *>::const_iterator it = _shapes.begin(); it != _shapes.end(); ++it)
            (*it)->move(deltaX, deltaY);
    }
};

