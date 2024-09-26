#pragma once

#include "./observer/subject.h"

class Drawing : public Subject
{
private:
    vector<Shape *> _shapes;
public:
    Drawing(vector<Shape *> shapes) : _shapes(shapes){}

    ~Drawing(){
        for(Shape *s : _shapes){
            delete s;
        }
    }

    vector<Shape *> shapes(){
        return _shapes;
    }
};