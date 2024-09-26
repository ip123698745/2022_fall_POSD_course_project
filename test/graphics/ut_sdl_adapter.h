#include "../../src/shape.h"
#include "../../src/rectangle.h"
#include "../../src/circle.h"
#include "../../src/triangle.h"
#include "../../src/compound_shape.h"
#include "../../src/graphics/sdl_adapter.h"
#include "mock_sdl_renderer.h"

class SDLAdapterTest : public ::testing::Test
{
protected:
    MockSDLRenderer *mockSDLRenderer;

    void SetUp() override
    {
        mockSDLRenderer = new MockSDLRenderer();
    }

    void TearDown() override
    {
        delete mockSDLRenderer;
    }
};

TEST_F(SDLAdapterTest, initShouldBeCalledWhenAdapterIsInitialized)
{
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    
    ASSERT_TRUE(mockSDLRenderer->isInitCalled());

    delete canvas;
}

TEST_F(SDLAdapterTest, initCalledArgsShouldBeCorrect)
{
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    
    ASSERT_EQ(1024, mockSDLRenderer->initWidth());
    ASSERT_EQ(768, mockSDLRenderer->initHeight());

    delete canvas;
}

TEST_F(SDLAdapterTest, widthAndHeightShouldBeGreaterThanZero)
{
    ASSERT_ANY_THROW(SDLAdapter(0, 768, mockSDLRenderer));
    ASSERT_ANY_THROW(SDLAdapter(1024, 0, mockSDLRenderer));
}

TEST_F(SDLAdapterTest, renderDrawCircleCalledArgsShouldBeCorrect)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    
    canvas->drawCircle(c1);

    ASSERT_NEAR(-2, mockSDLRenderer->renderDrawCircleCalledArgs()[0], 0.001);
    ASSERT_NEAR(1, mockSDLRenderer->renderDrawCircleCalledArgs()[1], 0.001);
    ASSERT_NEAR(c1->radius(), mockSDLRenderer->renderDrawCircleCalledArgs()[2], 0.001);

    delete c1;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderDrawLinesCalledArgsShouldBeCorrectForTriangle)
{
    Triangle *t1 = new Triangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    Canvas *canvas = new SDLAdapter(600, 600, mockSDLRenderer);

    canvas->drawTriangle(t1);
    const double *calledPoints = mockSDLRenderer->renderDrawLinesCalledPoints();
    
    ASSERT_NEAR(-2, calledPoints[0], 0.001);
    ASSERT_NEAR(1, calledPoints[1], 0.001);
    ASSERT_NEAR(-1.47, calledPoints[2], 0.001);
    ASSERT_NEAR(4.5, calledPoints[3], 0.001);
    ASSERT_NEAR(1.5, calledPoints[4], 0.001);
    ASSERT_NEAR(0.47, calledPoints[5], 0.001);

    delete t1;
    delete[] calledPoints;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderDrawLinesCalledArgsShouldBeCorrectForNonRotatedRectangle)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(0, 0), Point(3, 0)),
        TwoDimensionalVector(Point(3, 4), Point(3, 0)));
    Canvas *canvas = new SDLAdapter(600, 600, mockSDLRenderer);

    canvas->drawRectangle(r1);
    const double *calledPoints = mockSDLRenderer->renderDrawLinesCalledPoints();
    
    ASSERT_NEAR(0, calledPoints[0], 0.001);
    ASSERT_NEAR(0, calledPoints[1], 0.001);
    ASSERT_NEAR(0, calledPoints[2], 0.001);
    ASSERT_NEAR(4, calledPoints[3], 0.001);
    ASSERT_NEAR(3, calledPoints[4], 0.001);
    ASSERT_NEAR(4, calledPoints[5], 0.001);
    ASSERT_NEAR(3, calledPoints[6], 0.001);
    ASSERT_NEAR(0, calledPoints[7], 0.001);

    delete r1;
    delete[] calledPoints;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderDrawLinesCalledArgsShouldBeCorrectForRotatedRectangle)
{
    Rectangle *r1 = new Rectangle(
        TwoDimensionalVector(Point(-2, 1), Point(1.5, 0.47)),
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));
    Canvas *canvas = new SDLAdapter(600, 600, mockSDLRenderer);

    canvas->drawRectangle(r1);
    const double *calledPoints = mockSDLRenderer->renderDrawLinesCalledPoints();
    
    ASSERT_NEAR(-2, calledPoints[0], 0.001);
    ASSERT_NEAR(1, calledPoints[1], 0.001);
    ASSERT_NEAR(-1.47, calledPoints[2], 0.001);
    ASSERT_NEAR(4.5, calledPoints[3], 0.001);
    ASSERT_NEAR(2.03, calledPoints[4], 0.001);
    ASSERT_NEAR(3.97, calledPoints[5], 0.001);
    ASSERT_NEAR(1.5, calledPoints[6], 0.001);
    ASSERT_NEAR(0.47, calledPoints[7], 0.001);

    delete r1;
    delete[] calledPoints;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderPresentShouldBeCalledWhenAdapterIsDisplayed)
{
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);

    canvas->display();

    ASSERT_TRUE(mockSDLRenderer->isRenderPresentCalled());

    delete canvas;
}
