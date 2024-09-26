#include "../../src/builder/shape_builder.h"

// TEST(ShapeBuilderTest, testBuildCircleShouldBeCorrect)
// {
//     ShapeBuilder *builder = new ShapeBuilder();
//     builder->buildCircle(Point(0, 0), Point(3, 0));
//     vector<Shape *> result = builder->getResult();

//     ASSERT_NEAR(28.2743, result.at(0)->area(), 0.001);

//     delete builder;
// }

// TEST(ShapeBuilderTest, testBuildTriangleShouldBeCorrect)
// {
//     ShapeBuilder *builder = new ShapeBuilder();
//     builder->buildTriangle(Point(-2, 1), Point(1.5, 0.47), Point(-1.47, 4.5));
//     vector<Shape *> result = builder->getResult();

//     ASSERT_NEAR(6.2655, result.at(0)->area(), 0.001);

//     delete builder;
// }

// TEST(ShapeBuilderTest, testBuildRectangleShouldBeCorrect)
// {
//     ShapeBuilder *builder = new ShapeBuilder();
//     builder->buildRectangle(Point(3, 0), Point(0, 0), Point(3, 4));
//     vector<Shape *> result = builder->getResult();

//     ASSERT_NEAR(12, result.at(0)->area(), 0.001);

//     delete builder;
// }

// TEST(ShapeBuilderTest, testBuildCompoundShapeShouldBeCorrect)
// {
//     ShapeBuilder *builder = new ShapeBuilder();
//     builder->buildCompoundShape();
//     builder->buildTriangle(Point(-2, 1), Point(1.5, 0.47), Point(-1.47, 4.5));
//     builder->buildRectangle(Point(3, 0), Point(0, 0), Point(3, 4));
//     builder->buildCompoundEnd();
//     vector<Shape *> result = builder->getResult();

//     ASSERT_NEAR(12 + 6.2655, result.at(0)->area(), 0.001);

//     delete builder;
// }

// TEST(ShapeBuilderTest, testTraverseCompoundShapeShouldBeCorrect)
// {
//     ShapeBuilder *builder = new ShapeBuilder();
//     builder->buildCompoundShape();
//     builder->buildCircle(Point(0, 0), Point(3, 0));
//     builder->buildCompoundShape();
//     builder->buildTriangle(Point(-2, 1), Point(1.5, 0.47), Point(-1.47, 4.5));
//     builder->buildRectangle(Point(3, 0), Point(0, 0), Point(3, 4));
//     builder->buildCompoundEnd();
//     builder->buildCompoundEnd();
//     vector<Shape *> result = builder->getResult();

//     Iterator *csit = result.at(0)->createIterator(IteratorFactory::getInstance("DFS"));

//     ASSERT_NEAR(28.2743 + 12 + 6.2655, result.at(0)->area(), 0.001);
//     ASSERT_NEAR(28.2743, csit->currentItem()->area(), 0.001);
//     csit->next();
//     ASSERT_NEAR(12 + 6.2655, csit->currentItem()->area(), 0.001);
//     csit->next();
//     ASSERT_NEAR(6.2655, csit->currentItem()->area(), 0.001);
//     csit->next();
//     ASSERT_NEAR(12, csit->currentItem()->area(), 0.001);
//     csit->next();
//     ASSERT_TRUE(csit->isDone());

//     delete csit;
//     delete builder;
// }

// TEST(ShapeBuilderTest, testBuildShapesShouldBeCorrect)
// {
//     ShapeBuilder *builder = new ShapeBuilder();
//     builder->buildCompoundShape();
//     builder->buildCircle(Point(0, 0), Point(3, 0));
//     builder->buildCompoundShape();
//     builder->buildTriangle(Point(-2, 1), Point(1.5, 0.47), Point(-1.47, 4.5));
//     builder->buildRectangle(Point(3, 0), Point(0, 0), Point(3, 4));
//     builder->buildCompoundEnd();
//     builder->buildCompoundEnd();
//     builder->buildCompoundShape();
//     builder->buildTriangle(Point(-2, 1), Point(1.5, 0.47), Point(-1.47, 4.5));
//     builder->buildRectangle(Point(3, 0), Point(0, 0), Point(3, 4));
//     builder->buildCompoundEnd();
//     vector<Shape *> result = builder->getResult();

//     ASSERT_NEAR(28.2743 + 12 + 6.2655, result.at(0)->area(), 0.001);
//     ASSERT_NEAR(12 + 6.2655, result.at(1)->area(), 0.001);

//     delete builder;
// }

class ShapeBuilderTest : public ::testing::Test
{
protected:
    Point *A, *B, *C, *D, *E;

    ShapeBuilder *builder;

    void SetUp() override
    {
        A = new Point(0, 0);
        B = new Point(3, 0);
        C = new Point(0, 4);
        D = new Point(5, 0);
        E = new Point(0, 2);

        builder = new ShapeBuilder();
    }

    void TearDown() override
    {
        delete A;
        delete B;
        delete C;
        delete D;
        delete E;
        delete builder;
    }
};

TEST_F(ShapeBuilderTest, BuildCircleShouldBeCorrect)
{
    builder->buildCircle(*A, *B);
    std::vector<Shape*> result = builder->getResult();

    ASSERT_NEAR(9*M_PI, result.at(0)->area() , 0.001);
    delete *(result.begin());
}

TEST_F(ShapeBuilderTest, BuildTriangleShouldBeCorrect)
{
    builder->buildTriangle(*A, *B, *C);
    std::vector<Shape*> result = builder->getResult();

    ASSERT_NEAR(6, result.at(0)->area() , 0.001);
    delete *(result.begin());
}

TEST_F(ShapeBuilderTest, BuildRectangleShouldBeCorrect)
{
    builder->buildRectangle(*A, *D, *E);
    std::vector<Shape*> result = builder->getResult();

    ASSERT_NEAR(10, result.at(0)->area() , 0.001);
    delete *(result.begin());
}

TEST_F(ShapeBuilderTest, BuildSimpleCompoundShouldBeCorrect)
{
    builder->buildCompoundShape();
    builder->buildCircle(*A, *B);
    builder->buildRectangle(*A, *D, *E);
    builder->buildCompoundEnd();
    std::vector<Shape*> result = builder->getResult();

    ASSERT_NEAR(9*M_PI + 10, result.at(0)->area() , 0.001);
    delete *(result.begin());
}

TEST_F(ShapeBuilderTest, BuildComplexCompoundShouldBeCorrect)
{
    builder->buildCompoundShape();
    builder->buildCircle(*A, *B);
    builder->buildCompoundShape();
    builder->buildTriangle(*A, *B, *C);
    builder->buildRectangle(*A, *D, *E);
    builder->buildCompoundEnd();
    builder->buildCompoundEnd();
    std::vector<Shape*> result = builder->getResult();

    ASSERT_NEAR(9*M_PI + 6 + 10, result.at(0)->area() , 0.001);

    Iterator *it = result.at(0)->createIterator(IteratorFactory::getInstance("BFS"));
    ASSERT_FALSE(it->isDone());
    ASSERT_NEAR(9*M_PI, it->currentItem()->area() , 0.001);
    ASSERT_NO_THROW(it->next());
    ASSERT_NEAR(10 + 6, it->currentItem()->area() , 0.001);
    ASSERT_NO_THROW(it->next());
    ASSERT_NEAR(6, it->currentItem()->area() , 0.001);
    ASSERT_NO_THROW(it->next());
    ASSERT_NEAR(10, it->currentItem()->area() , 0.001);

    delete it;
    delete *(result.begin());
}

TEST_F(ShapeBuilderTest, BuildMultipleShapeShouldBeCorrect)
{
    builder->buildCircle(*A, *B);
    builder->buildTriangle(*A, *B, *C);
    std::vector<Shape*> result = builder->getResult();

    ASSERT_NEAR(9*M_PI, result.at(0)->area() , 0.001);
    ASSERT_NEAR(6, result.at(1)->area() , 0.001);
    delete *(result.begin());
    delete *(result.begin()+1);
}