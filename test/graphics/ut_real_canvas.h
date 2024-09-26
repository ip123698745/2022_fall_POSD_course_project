#include "../../src/graphics/real_canvas.h"
#include "../../src/circle.h"
#include "./mock_sdl_renderer.h"
#include "../../src/graphics/sdl_adapter.h"

TEST(RealCanvasTest, testUpdateShouldBeCorrect)
{
    Circle *c1 = new Circle(
        TwoDimensionalVector(Point(-2, 1), Point(-1.47, 4.5)));

    vector<Shape *> shapes = {c1};
    Drawing *drawing = new Drawing(shapes);
    MockSDLRenderer *renderer = new MockSDLRenderer();
    Canvas *canvas = new SDLAdapter(1024, 768, renderer);

    RealCanvas *realcanvas = new RealCanvas(canvas, drawing);
    realcanvas->update();

    ASSERT_NEAR(-2, renderer->renderDrawCircleCalledArgs()[0], 0.001);
    ASSERT_NEAR(1, renderer->renderDrawCircleCalledArgs()[1], 0.001);
    ASSERT_NEAR(c1->radius(), renderer->renderDrawCircleCalledArgs()[2], 0.001);

    delete drawing;
    delete renderer;
    delete canvas;
    delete realcanvas;
}