#include "../../src/visitor/collision_detector.h"

TEST(CollisionDetectorTest, testCircleShouldNotCollide)
{
    Shape *t1 = new Triangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0))
    );

    Shape *c1 = new Circle(
        TwoDimensionalVector(
            Point(-4.284, 0.264), 
            Point(-4.827, 0.728))
    );

    CollisionDetector *visitor = new CollisionDetector(t1);
    c1->accept(visitor);
    vector<Shape *> scores = visitor->collidedShapes();

    ASSERT_TRUE(scores.empty());

    delete t1;
    delete c1;
    delete visitor;
}

TEST(CollisionDetectorTest, testTriangleShouldBeCollide)
{
    Shape *r1 = new Rectangle(
        TwoDimensionalVector(Point(1.5, 0.47), Point(-2, 1)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    Shape *t1 = new Triangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0))
    );

    CollisionDetector *visitor = new CollisionDetector(r1);
    t1->accept(visitor);
    vector<Shape *> scores = visitor->collidedShapes();

    ASSERT_EQ(t1, scores[0]);

    delete r1;
    delete t1;
    delete visitor;
}

TEST(CollisionDetectorTest, testRectangleShouldBeCollide)
{
    Shape *t1 = new Triangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0))
    );

    Shape *r1 = new Rectangle(
        TwoDimensionalVector(Point(1.5, 0.47), Point(-2, 1)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5))
    );

    CollisionDetector *visitor = new CollisionDetector(t1);
    r1->accept(visitor);
    vector<Shape *> scores = visitor->collidedShapes();

    ASSERT_EQ(r1, scores[0]);

    delete t1;
    delete r1;
    delete visitor;
}

TEST(CollisionDetectorTest, testCompoundShapeShouldBeCollide)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(
            Point(-4.284, 0.264), 
            Point(-4.827, 0.728))
    );

    Shape *t1 = new Triangle(
        TwoDimensionalVector(
            Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(
            Point(-2, 1), Point(-1.47, 4.5))
    );

    Shape *r1 = new Rectangle(
        TwoDimensionalVector(
            Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(
            Point(3, 4), Point(3, 0))
    );

    Shape *c2 = new Circle(
        TwoDimensionalVector(
                Point(1.3449, -1.999),
                Point(6.0, 7))
    );

    Shape *cs1 = new CompoundShape();
    cs1->addShape(t1);
    cs1->addShape(r1);

    Shape *cs2 = new CompoundShape();
    cs2->addShape(c1);
    cs2->addShape(cs1);

    CollisionDetector *visitor = new CollisionDetector(c2);
    cs2->accept(visitor);
    vector<Shape *> scores = visitor->collidedShapes();

    ASSERT_EQ(c1, scores[0]);
    ASSERT_EQ(t1, scores[1]);
    ASSERT_EQ(r1, scores[2]);
    ASSERT_TRUE(scores.size() == 3);

    delete cs2;
    delete c2;
    delete visitor;
}