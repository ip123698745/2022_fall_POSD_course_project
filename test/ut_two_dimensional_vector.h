#include "../src/two_dimensional_vector.h"

TEST(TwoDimensionalVectorTest, testPointA)
{
    Point a(3, 4);
    Point b(0, 0);
    TwoDimensionalVector v1(a, b);

    ASSERT_EQ(v1.a(), a);
}

TEST(TwoDimensionalVectorTest, testPointB)
{
    Point a(3, 4);
    Point b(0, 0);
    TwoDimensionalVector v1(a, b);

    ASSERT_EQ(v1.b(), b);
}

TEST(TwoDimensionalVectorTest, testLength)
{
    Point a(3, 4);
    Point b(0, 0);
    TwoDimensionalVector v1(a, b);

    ASSERT_NEAR(v1.length(), 5, 0.001);
}

TEST(TwoDimensionalVectorTest, testLength2)
{
    Point a(-8.42, 3.42);
    Point b(-3.38, 4.3);
    TwoDimensionalVector v1(a, b);

    ASSERT_NEAR(v1.length(), 5.1162, 0.001);
}

TEST(TwoDimensionalVectorTest, testDot)
{
    Point a(0, 0);
    Point b(3, 0);
    Point c(4, 0);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);

    ASSERT_NEAR(v1.dot(v2), 12, 0.001);
}

TEST(TwoDimensionalVectorTest, testDot2)
{
    Point a(-2, 1);
    Point b(1.5, 0.47);
    Point c(-1.47, 4.5);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);

    ASSERT_NEAR(v1.dot(v2), 0, 0.001);
}

TEST(TwoDimensionalVectorTest, testCross)
{
    Point a(-2, 1);
    Point b(1.5, 0.47);
    Point c(-1.47, 4.5);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);

    ASSERT_NEAR(v1.cross(v2), 12.5309, 0.001);
}

TEST(TwoDimensionalVectorTest, testCross2)
{
    Point a(1, 1);
    Point b(10, 10);
    Point c(3, 3);
    TwoDimensionalVector v1(a, b);
    TwoDimensionalVector v2(a, c);

    ASSERT_NEAR(v1.cross(v2), 0, 0.001);
}

TEST(TwoDimensionalVectorTest, testInfo)
{
    Point a(-8.42, 3.42);
    Point b(-3.38, 4.3);
    TwoDimensionalVector v1(a, b);

    ASSERT_EQ(v1.info(), "Vector ((-8.42, 3.42), (-3.38, 4.30))");
}