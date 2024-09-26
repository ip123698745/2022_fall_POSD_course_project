#pragma once

#include "../iterator.h"
#include <list>
#include <map>
#include <string>

using namespace std;

class IteratorFactory
{
public:
    virtual Iterator *createIterator() = 0;
    virtual Iterator *createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end) = 0;
    static IteratorFactory* getInstance(string name);
protected:
    static void _register(string name, IteratorFactory *factory);
private:
    static map<string, IteratorFactory *> getFactory;
};