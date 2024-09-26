#pragma once

#include "./canvas.h"
#include "./sdl/sdl_renderer.h"
#include "../circle.h"
#include "../triangle.h"
#include <set>
#include <vector>

class SDLAdapter : public Canvas
{
private:
    SDL *_sdlRenderer;

public:
    SDLAdapter(int width, int height, SDL *sdlRenderer){
        if(width <= 0 || height <= 0){
            throw "width and height should be greater than zero";
        }

        sdlRenderer->init(width, height);
        _sdlRenderer = sdlRenderer;
    }

    void drawCircle(Circle *cir) override
    {
        set<Point> circlePoints = cir->getPoints();
        vector<Point> points;
        
        for(Point p : circlePoints){
            points.push_back(p);
        }

        _sdlRenderer->renderDrawCircle(
            (points.at(0).x() + points.at(1).x()) / 2,
            (points.at(0).y() + points.at(1).y()) / 2,
            cir->radius()
        );
    }

    void drawTriangle(Triangle *tri) override
    {
        set<Point> trianglePoints = tri->getPoints();
        double *points = new double[6];
        int index = 0;

        for(Point p : trianglePoints){
            points[index++] = p.x();
            points[index++] = p.y();
        }

        _sdlRenderer->renderDrawLines(points, 6);
    }

    void drawRectangle(Rectangle *rect) override
    {
        set<Point> rectPointsSet = rect->getPoints();
        vector<Point> reverseLastTwoPoints(rectPointsSet.begin(), rectPointsSet.end());

        Point temp = reverseLastTwoPoints[2];
        reverseLastTwoPoints[2] = reverseLastTwoPoints[3];
        reverseLastTwoPoints[3] = temp;

        double *points = new double[8];
        int index = 0;

        for(Point p : reverseLastTwoPoints){
            points[index++] = p.x();
            points[index++] = p.y();
        }

        _sdlRenderer->renderDrawLines(points, 8);
    }

    void display() override
    {
        _sdlRenderer->renderPresent();
    }
};