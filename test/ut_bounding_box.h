#include "../src/bounding_box.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"

TEST(BoundingBoxTest, testBoundingBoxShouldThrowExceptionWhenSetIsEmpty)
{
    set<Point> emptySet;

    ASSERT_ANY_THROW(new BoundingBox(emptySet));
}

TEST(BoundingBoxTest, testCircleBoundingBoxMaxPoint)
{
    Point p(11.4766, 8.1327);

    Shape *c1 = new Circle(
        TwoDimensionalVector(
                Point(1.3449, -1.999),
                Point(6.0, 7))
    );

    BoundingBox *c1bb = new BoundingBox(c1->getPoints());
    
    ASSERT_TRUE((c1bb->max()) == p);

    delete c1;
    delete c1bb;
}

TEST(BoundingBoxTest, testCircleBoundingBoxMinPoint)
{
    Point p(-8.7868, -12.1307);

    Shape *c1 = new Circle(
        TwoDimensionalVector(
                Point(1.3449, -1.999),
                Point(6.0, 7))
    );

    BoundingBox *c1bb = new BoundingBox(c1->getPoints());

    ASSERT_TRUE((c1bb->min()) == p);

    delete c1;
    delete c1bb;
}

TEST(BoundingBoxTest, testRectangleBoundingBoxMaxPoint)
{
    Point p(2.03, 4.5);

    Shape *r1 = new Rectangle(
        TwoDimensionalVector(Point(1.5, 0.47), Point(-2, 1)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    BoundingBox *r1bb;

    ASSERT_TRUE((r1bb->calMaximumPoint(r1->getPoints())) == p);

    delete r1;
}

TEST(BoundingBoxTest, testRectangleBoundingBoxMinPoint)
{
    Point p(-2, 0.47);

    Shape *r1 = new Rectangle(
        TwoDimensionalVector(Point(1.5, 0.47), Point(-2, 1)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    BoundingBox *r1bb;

    ASSERT_TRUE((r1bb->calMinimumPoint(r1->getPoints())) == p);

    delete r1;
}

TEST(BoundingBoxTest, testTriangleBoundingBoxMaxPoint)
{
    Point p(3, 4);

    Shape *t1 = new Triangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0))
    );

    BoundingBox *t1bb = new BoundingBox(t1->getPoints());

    ASSERT_TRUE((t1bb->max()) == p);

    delete t1;
    delete t1bb;
}

TEST(BoundingBoxTest, testTriangleBoundingBoxMinPoint)
{
    Point p(0, 0);

    Shape *t1 = new Triangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0))
    );

    BoundingBox *t1bb = new BoundingBox(t1->getPoints());

    ASSERT_TRUE((t1bb->min()) == p);

    delete t1;
    delete t1bb;
}

TEST(BoundingBoxTest, testCompoundShapeBoundingBoxMaxPoint)
{
    Point p(3, 4.5);

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

    Shape *cs1 = new CompoundShape();
    cs1->addShape(t1);
    cs1->addShape(r1);

    Shape *cs2 = new CompoundShape();
    cs2->addShape(c1);
    cs2->addShape(cs1);

    BoundingBox *cs2bb = new BoundingBox(cs2->getPoints());

    ASSERT_TRUE((cs2bb->max()) == p);

    delete cs2;
    delete cs2bb;
}

TEST(BoundingBoxTest, testCompoundShapeBoundingBoxMinPoint)
{
    Point p(-4.9982, -0.4502);

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

    Shape *cs1 = new CompoundShape();
    cs1->addShape(t1);
    cs1->addShape(r1);

    Shape *cs2 = new CompoundShape();
    cs2->addShape(c1);
    cs2->addShape(cs1);

    BoundingBox *cs2bb = new BoundingBox(cs2->getPoints());

    ASSERT_TRUE((cs2bb->min()) == p);

    delete cs2;
    delete cs2bb;
}

TEST(BoundingBoxTest, testBoundingBoxShouldBeCollide)
{
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

    BoundingBox *t1bb = new BoundingBox(t1->getPoints());
    BoundingBox *r1bb = new BoundingBox(r1->getPoints());

    ASSERT_TRUE(t1bb->collide(r1bb));

    delete t1;
    delete r1;
    delete t1bb;
    delete r1bb;
}

TEST(BoundingBoxTest, testBoundingBoxShouldNotCollide)
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

    BoundingBox *c1bb = new BoundingBox(c1->getPoints());
    BoundingBox *t1bb = new BoundingBox(t1->getPoints());

    ASSERT_FALSE(c1bb->collide(t1bb));

    delete c1;
    delete t1;
    delete c1bb;
    delete t1bb;
}