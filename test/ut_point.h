#include "../src/point.h"

TEST(PointTest, testX)
{
    Point p1(0.235, 0.246);

    ASSERT_DOUBLE_EQ(p1.x(), 0.235);
}

TEST(PointTest, testY)
{
    Point p1(0.235, 0.246);

    ASSERT_DOUBLE_EQ(p1.y(), 0.246);
}

TEST(PointTest, testOperatorEqual)
{
    Point p1(0.235, 0.246);
    Point p2(0.246, 0.235);

    ASSERT_FALSE(p1 == p2);
}

TEST(PointTest, testOperatorEqual2)
{
    Point p1(0.2457, 0.2367);
    Point p2(0.2457, 0.2367);

    ASSERT_TRUE(p1 == p2);
}

TEST(PointTest, testInfo)
{
    Point p1(0.235, 0.2446);

    ASSERT_EQ(p1.info(), "(0.24, 0.24)");
}

TEST(PointTest, testInfo2)
{
    Point p1(2, 4.115);

    ASSERT_EQ(p1.info(), "(2.00, 4.12)");
}