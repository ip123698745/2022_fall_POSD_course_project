#pragma once

#include "iterator.h"
#include "../shape.h"
#include "./factory/bfs_iterator_factory.h"
#include <list>
#include <queue>
#include <map>

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator
{
private:
    list<Shape *> _BFSshapes;
    list<Shape *>::iterator _current;
    map<Shape *, bool> isVisited;

    void BFS(ForwardIterator begin, ForwardIterator end){
        list<Shape *> queue;

        for(ForwardIterator it = begin; it != end; it++)
        {
            isVisited[*it] = false;
            queue.push_back(*it);
        }

        while (!queue.empty()){
            Shape *shape = queue.front();
            _BFSshapes.push_back(shape);
            queue.pop_front();
            
            Iterator *iter = shape->createIterator(IteratorFactory::getInstance("BFS"));
            if(!iter->isDone()){
                for(; !iter->isDone(); iter->next()){
                    if(!isVisited[iter->currentItem()]){
                        queue.push_back(iter->currentItem());
                        isVisited[iter->currentItem()] = true;
                    }
                }
            }
            delete iter;
        }
    }

public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end) {
        BFS(begin, end);
        first();
    }

    void first() override {
        _current = _BFSshapes.begin();
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
        return _current == _BFSshapes.end();
    }
};
