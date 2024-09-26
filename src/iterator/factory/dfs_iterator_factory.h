#pragma once

#include "./iterator_factory.h"

class DFSIteratorFactory : public IteratorFactory 
{
public:
    Iterator *createIterator();
    Iterator *createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end);
private:
    DFSIteratorFactory();
    static DFSIteratorFactory dfsIterFactory;
};