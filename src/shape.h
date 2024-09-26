#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <set>
#include "./point.h"
#include "./iterator/iterator.h"
#include "./iterator/factory/iterator_factory.h"
#include "./iterator/factory/bfs_iterator_factory.h"
#include "./iterator/factory/dfs_iterator_factory.h"
#include "./iterator/factory/list_iterator_factory.h"
#include "./visitor/shape_visitor.h"

using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string info() = 0;
    virtual ~Shape() {}
    virtual Iterator *createIterator(IteratorFactory *factory) = 0;
    virtual set<Point> getPoints() = 0;
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual void addShape(Shape *shape) = 0;
    virtual void deleteShape(Shape *shape) = 0;
    virtual void move(double deltaX, double deltaY) = 0;
};

#endif