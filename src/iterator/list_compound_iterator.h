#pragma once

#include "../shape.h"
#include "./iterator.h"
#include <list>

template <class ForwardIterator>
class ListCompoundIterator : public Iterator
{
private:
    list<Shape *> _childshapes;
    list<Shape *>::iterator _current;
public:
    ListCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        for(ForwardIterator it = begin; it != end; it++)
        {
            _childshapes.push_back(*it);
        }
        
        first();
    }

    void first() override {
        _current = _childshapes.begin();
    }

    Shape *currentItem() const override {
        if(isDone()){
            throw "No shape in the current iterator";
        }

        return *_current;
    }

    void next() override {
        if(isDone()){
            throw "No shape in the next iterator";
        }

        _current++;
    }

    bool isDone() const override {
        return _current == _childshapes.end();
    }
};