#pragma once

#include "./scanner.h"
#include "./shape_builder.h"

class ShapeParser
{
private:
    Scanner *_scanner;
    ShapeBuilder *_builder;
    vector<Point> _points;
    double x, y;

    void ScannerNext(int count){
        for(int i = 0; i < count; i++){
            _scanner->next();
        }
    }

    vector<Point> ProcessCommonPoint(){
        vector<Point> points;

        if((_points.at(0)) == (_points.at(2))){
            points.push_back(_points.at(0));
            points.push_back(_points.at(1));
            points.push_back(_points.at(3));
        }
        else if((_points.at(0)) == (_points.at(3))){
            points.push_back(_points.at(0));
            points.push_back(_points.at(1));
            points.push_back(_points.at(2));
        }
        else if((_points.at(1)) == (_points.at(2))){
            points.push_back(_points.at(1));
            points.push_back(_points.at(0));
            points.push_back(_points.at(3));
        }
        else if((_points.at(1)) == (_points.at(3))){
            points.push_back(_points.at(1));
            points.push_back(_points.at(0));
            points.push_back(_points.at(2));
        }

        return points;
    }

    void parseCircle(){
        _points.clear();

        ScannerNext(4);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(3);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        _builder->buildCircle(_points.at(0), _points.at(1));
        ScannerNext(3);
    }

    void parseTriangle(){
        _points.clear();

        ScannerNext(4);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(3);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(6);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(3);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        vector<Point> points = ProcessCommonPoint();
        _builder->buildTriangle(points.at(0), points.at(1), points.at(2));
        ScannerNext(3);
    }

    void parseRectangle(){
        _points.clear();
        
        ScannerNext(4);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(3);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(6);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        ScannerNext(3);
        x = _scanner->nextDouble();
        ScannerNext(1);
        y = _scanner->nextDouble();
        _points.push_back(Point(x, y));
        vector<Point> points = ProcessCommonPoint();
        _builder->buildRectangle(points.at(0), points.at(1), points.at(2));
        ScannerNext(3);
    }

public:
    ShapeParser(string input) {
        _scanner = new Scanner(input);
        _builder = new ShapeBuilder();
    }

    ~ShapeParser() {
        delete _scanner;
        delete _builder;
    }

    void parse() {
        string token = "";

        while (!_scanner->isDone())
        {
            token = _scanner->next();

            if(token == "Circle"){
                parseCircle();
            }
            else if(token == "Triangle"){
                parseTriangle();
            }
            else if(token == "Rectangle"){
                parseRectangle();
            }
            else if(token == "CompoundShape"){
                _builder->buildCompoundShape();
                _scanner->next();
            }
            else if(token == ")"){
                _builder->buildCompoundEnd();
            }
        }
    }

    vector<Shape *> getResult() {
        return _builder->getResult();
    }
};
