#pragma once

#include "./shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/list_iterator_factory.h"
#include <vector>

class CollisionDetector : public ShapeVisitor
{
private:
    std::vector<Shape *> _collideResult;
    BoundingBox *_targetBoundingBox;

public:
    CollisionDetector(Shape *shape) {
        _targetBoundingBox = new BoundingBox(shape->getPoints());
    }

    ~CollisionDetector() {
        delete _targetBoundingBox;
    }

    void visitCircle(Circle *circle) override {
        BoundingBox *_sourceBoundingBox = new BoundingBox(circle->getPoints());
        if(_sourceBoundingBox->collide(_targetBoundingBox))
        {
            _collideResult.push_back(circle);
        }

        delete _sourceBoundingBox;
    }

    void visitTriangle(Triangle *triangle) override {
        BoundingBox *_sourceBoundingBox = new BoundingBox(triangle->getPoints());
        if(_sourceBoundingBox->collide(_targetBoundingBox))
        {
            _collideResult.push_back(triangle);
        }

        delete _sourceBoundingBox;
    }

    void visitRectangle(Rectangle *rectangle) override {
        BoundingBox *_sourceBoundingBox = new BoundingBox(rectangle->getPoints());
        if(_sourceBoundingBox->collide(_targetBoundingBox))
        {
            _collideResult.push_back(rectangle);
        }

        delete _sourceBoundingBox;
    }

    void visitCompoundShape(CompoundShape *compoundShape) override {
        BoundingBox *_sourceBoundingBox = new BoundingBox(compoundShape->getPoints());
        if(_sourceBoundingBox->collide(_targetBoundingBox))
        {
            Iterator *csit = compoundShape->createIterator(IteratorFactory::getInstance("List"));

            for(csit->first(); !csit->isDone(); csit->next())
            {
                csit->currentItem()->accept(this);
            }

            delete csit;
        }
        delete _sourceBoundingBox;
    }

    std::vector<Shape *> collidedShapes() const {
        return _collideResult;
    }
};

