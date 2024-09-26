#include "../../src/graphics/drawing.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/triangle.h"

TEST(DrawingTest, testShapesShouldBeCorrect)
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

    vector<Shape *> shapes = {c1, t1, r1};

    Drawing *drawing = new Drawing(shapes);

    ASSERT_EQ(c1, drawing->shapes().at(0));
    ASSERT_EQ(t1, drawing->shapes().at(1));
    ASSERT_EQ(r1, drawing->shapes().at(2));
}