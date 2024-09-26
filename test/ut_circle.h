#include "../src/circle.h"
#include <queue>
#include <vector>
#include <algorithm>

TEST(CircleTest, testRadius)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    ASSERT_NEAR(c1->radius(), 3.5399, 0.001);

    delete c1;
}

TEST(CircleTest, testArea)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-4.284, 0.264), Point(-4.827, 0.728)));

    ASSERT_NEAR(c1->area(), 1.6027, 0.001);

    delete c1;
}

TEST(CircleTest, testArea2)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)));

    ASSERT_NEAR(c1->area(), 28.2743, 0.001);

    delete c1;
}

TEST(CircleTest, testArea3)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    ASSERT_NEAR(c1->area(), 39.3669, 0.001);

    delete c1;
}

TEST(CircleTest, testPerimeter)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-4.284, 0.264), Point(-4.827, 0.728)));

    ASSERT_NEAR(c1->perimeter(), 4.4877, 0.001);

    delete c1;
}

TEST(CircleTest, testPerimeter2)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)));

    ASSERT_NEAR(c1->perimeter(), 18.8496, 0.001);

    delete c1;
}

TEST(CircleTest, testPerimeter3)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    ASSERT_NEAR(c1->perimeter(), 22.2419, 0.001);

    delete c1;
}

TEST(CircleTest, testInfo)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-4.284, 0.264), Point(-4.827, 0.728)));

    ASSERT_EQ(c1->info(), "Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))");

    delete c1;
}

TEST(CircleTest, testaddShape)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Shape *c2 = new Circle(
        TwoDimensionalVector(Point(-4.284, 0.264), Point(-4.827, 0.728)));

    ASSERT_ANY_THROW(c1->addShape(c2));

    delete c1;
    delete c2;
}

TEST(CircleTest, testdeleteShape)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Shape *c2 = new Circle(
        TwoDimensionalVector(Point(-4.284, 0.264), Point(-4.827, 0.728)));

    ASSERT_ANY_THROW(c1->deleteShape(c2));

    delete c1;
    delete c2;
}

TEST(CircleTest, testnullIteratorWithIsDone)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Iterator *it = c1->createIterator(IteratorFactory::getInstance("DFS"));

    ASSERT_TRUE(it->isDone());

    delete c1;
    delete it;
}

TEST(CircleTest, testnullIteratorWithIsDone2)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    
    Iterator *it = c1->createIterator(IteratorFactory::getInstance("BFS"));

    ASSERT_TRUE(it->isDone());

    delete c1;
    delete it;
}

TEST(CircleTest, testgetPoints)
{
    Shape *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    Point p1(-5.5399, -2.5399);
    Point p2(1.5399, 4.5399);

    set<Point> points = c1->getPoints();

    ASSERT_TRUE(points.size() == 2);

    set<Point>::iterator it = points.begin();
    ASSERT_TRUE((*it) == p1);
    it++;
    ASSERT_TRUE((*it) == p2);

    delete c1;
}