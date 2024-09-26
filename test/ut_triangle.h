#include "../src/triangle.h"
#include <vector>
#include <algorithm>

TEST(TriangleTest, testisTriangle)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(1, 1);
    Point d(3, 3);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, d);

    ASSERT_ANY_THROW(Triangle(v1, v2));
}

TEST(TriangleTest, testisTriangle2)
{
    Point a(4.1, 5.1);
    Point b(8, 0);
    Point c(1, 1);
    Point d(3, 3);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, d);

    ASSERT_ANY_THROW(Triangle(v1, v2));
}

TEST(TriangleTest, testisTriangle3)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);

    ASSERT_NO_THROW(Triangle(v1, v2));
}

TEST(TriangleTest, testisTriangle4)
{
    Point a(1, 1);
    Point b(10, 10);
    Point c(3, 3);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);

    ASSERT_ANY_THROW(Triangle(v1, v2));
}

TEST(TriangleTest, testArea)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    Triangle t1(v1, v2);

    ASSERT_NEAR(t1.area(), 6, 0.001);
}

TEST(TriangleTest, testArea2)
{
    Point a(-2, 1);
    Point b(1.5, 0.47);
    Point c(-1.47, 4.5);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);
    Triangle t1(v1, v2);

    ASSERT_NEAR(t1.area(), 6.2655, 0.001);
}

TEST(TriangleTest, testPerimeter)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    Triangle t1(v1, v2);

    ASSERT_NEAR(t1.perimeter(), 12, 0.001);
}

TEST(TriangleTest, testPerimeter2)
{
    Point a(-2, 1);
    Point b(1.5, 0.47);
    Point c(-1.47, 4.5);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);
    Triangle t1(v1, v2);

    ASSERT_NEAR(t1.perimeter(), 12.0860, 0.001);
}

TEST(TriangleTest, testInfo)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    Triangle t1(v1, v2);

    ASSERT_EQ(t1.info(), "Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))");
}

TEST(TriangleTest, testaddShape)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    Point d(-2, 1);
    Point e(1.5, 0.47);
    Point f(-1.47, 4.5);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    TwoDimensionalVector v3(d, e);
    TwoDimensionalVector v4(d, f);

    Shape *t1 = new Triangle(v1, v2);
    Shape *t2 = new Triangle(v3, v4);

    ASSERT_ANY_THROW(t1->addShape(t2));

    delete t1;
    delete t2;
}

TEST(TriangleTest, testdeleteShape)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    Point d(-2, 1);
    Point e(1.5, 0.47);
    Point f(-1.47, 4.5);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    TwoDimensionalVector v3(d, e);
    TwoDimensionalVector v4(d, f);

    Shape *t1 = new Triangle(v1, v2);
    Shape *t2 = new Triangle(v3, v4);

    ASSERT_ANY_THROW(t1->deleteShape(t2));

    delete t1;
    delete t2;
}

TEST(TriangleTest, testNullIteratorWithIsDone)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    Triangle t1(v1, v2);
    Iterator *it = t1.createIterator(IteratorFactory::getInstance("DFS"));

    ASSERT_TRUE(it->isDone());

    delete it;
}

TEST(TriangleTest, testNullIteratorWithIsDone2)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    Triangle t1(v1, v2);
    Iterator *it = t1.createIterator(IteratorFactory::getInstance("DFS"));

    ASSERT_TRUE(it->isDone());

    delete it;
}

TEST(TriangleTest, testgetPoints)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(3, 4);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(c, b);
    Triangle t1(v1, v2);

    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(3, 4);

    set<Point> points = t1.getPoints();

    ASSERT_TRUE(points.size() == 3);

    set<Point>::iterator it = points.begin();
    ASSERT_TRUE((*it) == p1);
    it++;
    ASSERT_TRUE((*it) == p2);
    it++;
    ASSERT_TRUE((*it) == p3);
}