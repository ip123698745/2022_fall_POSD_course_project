#include "../src/rectangle.h"
#include <vector>
#include <algorithm>

TEST(RectangleTest, testisRectangle)
{
    ASSERT_NO_THROW(Rectangle(
        TwoDimensionalVector(Point(-2, 1),  Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1),  Point(-1.47, 4.5))));
}

TEST(RectangleTest, testisRectangle2)
{
    ASSERT_NO_THROW(Rectangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0))));
}

TEST(RectangleTest, testisRectangle3)
{
    ASSERT_ANY_THROW(Rectangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 5)),
        TwoDimensionalVector(Point(0, 0), Point(3, 0))));
}

TEST(RectangleTest, testisRectangle4)
{
    ASSERT_ANY_THROW(Rectangle(
        TwoDimensionalVector(Point(0, 0), Point(0, 5)),
        TwoDimensionalVector(Point(0, -1), Point(5.8, -1))));
}

TEST(RectangleTest, testLength)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    ASSERT_NEAR(r1->length(), 3.5399, 0.001);

    delete r1;
}

TEST(RectangleTest, testWidth)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    ASSERT_NEAR(r1->width(), 3.5399, 0.001);

    delete r1;
}

TEST(RectangleTest, testArea)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    ASSERT_NEAR(r1->area(), 12.5309, 0.001);

    delete r1;
}

TEST(RectangleTest, testArea2)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0)));
    
    ASSERT_NEAR(r1->area(), 12, 0.001);

    delete r1;
}

TEST(RectangleTest, testPerimeter)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0)));
    
    ASSERT_NEAR(r1->perimeter(), 14, 0.001);

    delete r1;
}

TEST(RectangleTest, testPerimeter2)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    ASSERT_NEAR(r1->perimeter(), 14.1596, 0.001);

    delete r1;
}

TEST(RectangleTest, testInfo)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    ASSERT_EQ(r1->info(), "Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))");

    delete r1;
}

TEST(RectangleTest, testaddShape)
{
    Shape* r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Shape* r2 = new Rectangle(
            TwoDimensionalVector(Point(0, 0), Point(3, 0)),
            TwoDimensionalVector(Point(3, 4), Point(3, 0)));

    ASSERT_ANY_THROW(r1->addShape(r2));
    
    delete r1;
    delete r2;
}

TEST(RectangleTest, testdeleteShape)
{
    Shape* r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Shape* r2 = new Rectangle(
            TwoDimensionalVector(Point(0, 0), Point(3, 0)),
            TwoDimensionalVector(Point(3, 4), Point(3, 0)));

    ASSERT_ANY_THROW(r1->deleteShape(r2));
    
    delete r1;
    delete r2;
}

TEST(RectangleTest, testnullIteratorWithIsDone)
{
    Shape* r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Iterator *it = r1->createIterator(IteratorFactory::getInstance("DFS"));

    ASSERT_TRUE(it->isDone());

    delete r1;
    delete it;
}

TEST(RectangleTest, testnullIteratorWithIsDone2)
{
    Shape* r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Iterator *it = r1->createIterator(IteratorFactory::getInstance("BFS"));

    ASSERT_TRUE(it->isDone());

    delete r1;
    delete it;
}

TEST(RectangleTest, testgetPoints)
{
    Shape *r1 = new Rectangle(
        TwoDimensionalVector(Point(1.5, 0.47), Point(-2, 1)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    Point p1(-2, 1);
    Point p2(-1.47, 4.5);
    Point p3(1.5, 0.47);
    Point p4(2.03, 3.97);

    set<Point> points = r1->getPoints();

    ASSERT_TRUE(points.size() == 4);

    set<Point>::iterator it = points.begin();
    ASSERT_TRUE((*it) == p1);
    it++;
    ASSERT_TRUE((*it) == p2);
    it++;
    ASSERT_TRUE((*it) == p3);
    it++;
    ASSERT_TRUE((*it) == p4);

    delete r1;
}