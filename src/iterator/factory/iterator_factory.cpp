#include "./iterator_factory.h"

map<string, IteratorFactory *> IteratorFactory::getFactory;

IteratorFactory *IteratorFactory::getInstance(string name)
{
    return getFactory[name];
}

void IteratorFactory::_register(string name, IteratorFactory *factory)
{
    getFactory[name] = factory;
}