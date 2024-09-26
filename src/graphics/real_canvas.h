#pragma once

#include "./observer/observer.h"
#include "./canvas.h"
#include "./drawing.h"
#include "../visitor/shape_printer.h"

class RealCanvas : public Observer
{
private:
    Canvas *_canvas;
    Drawing *_drawing;
    ShapePrinter *_printer;
public:
    RealCanvas(){}

    RealCanvas(Canvas *canvas, Drawing *drawing): _canvas(canvas), _drawing(drawing){
        _printer = new ShapePrinter(_canvas);
    }

    void update() override {
        vector<Shape *> shapes = _drawing->shapes();

        for (std::vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            Iterator *sit = (*it)->createIterator(IteratorFactory::getInstance("DFS"));
            (*it)->accept(_printer);
            for (; !sit->isDone(); sit->next())
                sit->currentItem()->accept(_printer);
        }
    }
};