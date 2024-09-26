#pragma once

#include "./iterator_factory.h"

class BFSIteratorFactory : public IteratorFactory 
{
public:
    Iterator *createIterator();
    Iterator *createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end);
private:
    BFSIteratorFactory();
    static BFSIteratorFactory bfsIterFactory;
};