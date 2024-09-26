#pragma once

#include "./iterator_factory.h"
#include "../list_compound_iterator.h"
#include "../null_iterator.h"

class ListIteratorFactory : public IteratorFactory 
{
public:
    Iterator *createIterator();
    Iterator *createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end);
private:
    ListIteratorFactory();
    static ListIteratorFactory listIterFactory;
};