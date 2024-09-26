#include "../src/compound_shape.h"
#include <vector>
#include <algorithm>

TEST(CompoundShapeTest, testArea)
{
    Shape *shapes[] = {
        new Circle( 
            TwoDimensionalVector(
                Point(1.3449, -1.999),
                Point(6.0, 7)
            )
        ),
        new Rectangle(
            TwoDimensionalVector(
                Point(-3, 3), Point(-1, 3)
            ),
            TwoDimensionalVector(
                Point(-1, 3), Point(-1, -1)
            )
        )
    };

    CompoundShape *cs = new CompoundShape(shapes, 2);

    ASSERT_NEAR(cs->area(), 330.4906, 0.001);

    delete cs;
}

TEST(CompoundShapeTest, testAreaAndAddShape)
{
    Shape *shapes[] = {
        new Circle(
            TwoDimensionalVector(
                Point(1.3449, -1.999),
                Point(6.0, 7)
            )
        ),
        new Rectangle(
            TwoDimensionalVector(
                Point(-3, 3), Point(-1, 3)
            ),
            TwoDimensionalVector(
                Point(-1, 3), Point(-1, -1)
            )
        )
    };

    Shape *shapes2[] = {
        new Triangle(
            TwoDimensionalVector(
                Point(-2, 1), Point(1.5, 0.47)
            ),
            TwoDimensionalVector(
                Point(-2, 1), Point(-1.47, 4.5)
            )
        ),
        new Rectangle(
            TwoDimensionalVector(
                Point(-2, 1), Point(1.5, 0.47)
            ),
            TwoDimensionalVector(
                Point(-2, 1), Point(-1.47, 4.5)
            )
        )
    };

    CompoundShape *cs = new CompoundShape(shapes, 2);
    CompoundShape *cs2 = new CompoundShape(shapes2, 2);

    cs->addShape(cs2);

    ASSERT_NEAR(cs->area(), 349.2870, 0.001);

    delete cs;
}

TEST(CompoundShapeTest, testPerimeter)
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

    Shape *cs = new CompoundShape(&r1, 1);

    Shape *shapes[] = {c1, t1, cs};

    Shape *cs2 = new CompoundShape(shapes, 3);

    ASSERT_NEAR(cs2->perimeter(), 30.5737, 0.001);

    delete cs2;
}

TEST(CompoundShapeTest, testPerimeterAndDeleteShape)
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

    Shape *shapes[] = {c1, t1, r1};

    Shape *cs = new CompoundShape(shapes, 3);

    cs->deleteShape(t1);

    ASSERT_NEAR(cs->perimeter(), 18.4877, 0.001);

    delete cs;
}

TEST(CompoundShapeTest, testInfo)
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

    Shape *cs = new CompoundShape(&r1, 1);

    Shape *shapes[] = {c1, t1, cs};

    Shape *cs2 = new CompoundShape(shapes, 3);

    ASSERT_EQ(cs2->info(), "CompoundShape (Circle (Vector ((-4.28, 0.26), (-4.83, 0.73))), Triangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50))), CompoundShape (Rectangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))))");

    delete cs2;
}

TEST(CompoundShapeTest, testgetPoints)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    Shape *t1 = new Triangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 0), Point(3, 4))
    );

    Shape *r1 = new Rectangle(
        TwoDimensionalVector(Point(1.5, 0.47), Point(-2, 1)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    Shape *cs1 = new CompoundShape();
    cs1->addShape(t1);
    cs1->addShape(r1);

    Shape *cs2 = new CompoundShape();
    cs2->addShape(c1);
    cs2->addShape(cs1);

    Point p1(-5.5399, -2.5399);
    Point p2(-2, 1);
    Point p3(-1.47, 4.5);
    Point p4(0, 0);
    Point p5(1.5, 0.47);
    Point p6(1.5399, 4.5399);
    Point p7(2.03, 3.97);
    Point p8(3, 0);
    Point p9(3, 4);

    set<Point> points = cs2->getPoints();

    ASSERT_TRUE(points.size() == 9);

    set<Point>::iterator it = points.begin();
    ASSERT_TRUE((*it) == p1);
    it++;
    ASSERT_TRUE((*it) == p2);
    it++;
    ASSERT_TRUE((*it) == p3);
    it++;
    ASSERT_TRUE((*it) == p4);
    it++;
    ASSERT_TRUE((*it) == p5);
    it++;
    ASSERT_TRUE((*it) == p6);
    it++;
    ASSERT_TRUE((*it) == p7);
    it++;
    ASSERT_TRUE((*it) == p8);
    it++;
    ASSERT_TRUE((*it) == p9);

    delete cs2;
}