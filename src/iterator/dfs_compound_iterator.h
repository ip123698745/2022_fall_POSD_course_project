#pragma once

#include "iterator.h"
#include "../shape.h"
#include "./factory/dfs_iterator_factory.h"
#include <list>

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator
{
private:
    list<Shape *> _DFSshapes;
    list<Shape *>::iterator _current;

    void DFS(ForwardIterator begin, ForwardIterator end){
        for(ForwardIterator it = begin; it != end; it++){
            _DFSshapes.push_back(*it);
            Iterator *iter = (*it)->createIterator(IteratorFactory::getInstance("DFS"));

            if(!iter->isDone())
            {
                for(iter->first(); !iter->isDone(); iter->next())
                {
                    _DFSshapes.push_back(iter->currentItem());
                }
            }
            delete iter;
        }
    }

public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        DFS(begin, end);
        first();
    }

    void first() override {
        _current = _DFSshapes.begin();
    }

    Shape* currentItem() const override {
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
        return _current == _DFSshapes.end();
    }
};
