#include "../../src/iterator/list_compound_iterator.h"
#include "../../src/compound_shape.h"
#include "../../src/shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"

class ListCompoundIteratorTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;
    Shape *c1, *r1, *c2, *r2;
    Iterator* it;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p1, *p3);
        vec3 = new TwoDimensionalVector(*p1, *p4);

        c1 = new Circle(*vec1);
        c2 = new Circle(*vec3);
        r1 = new Rectangle(*vec1,*vec2);
        r2 = new Rectangle(*vec2,*vec1);

        cs1 = new CompoundShape();
        cs1->addShape(c1);
        cs1->addShape(r1);

        cs2 = new CompoundShape();
        cs2->addShape(cs1);
        cs2->addShape(c2);
        cs2->addShape(r2);

        it = cs2->createIterator(IteratorFactory::getInstance("List"));
    }

    void TearDown() override
    {
        delete cs2;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete vec1;
        delete vec2;
        delete vec3;
        delete it;
    }
};

TEST_F(ListCompoundIteratorTest, CurrentItemShouldBeCorrect)
{
    ASSERT_EQ(5 * 5 * M_PI + 25, it->currentItem()->area());
}

TEST_F(ListCompoundIteratorTest, NextShouldBeCorrect)
{
    it->next();

    ASSERT_EQ(3 * 3 * M_PI, it->currentItem()->area());
}

TEST_F(ListCompoundIteratorTest, NextShouldBeCorrect2)
{
    it->next();
    it->next();

    ASSERT_EQ(25, it->currentItem()->area());
}

TEST_F(ListCompoundIteratorTest, IsDoneShouldBeCorrect)
{
    it->next();
    it->next();
    it->next();

    ASSERT_TRUE(it->isDone());
}

TEST_F(ListCompoundIteratorTest, CurrentItemShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->currentItem());
}

TEST_F(ListCompoundIteratorTest, NextShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->next());
}