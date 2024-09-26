#include "./list_iterator_factory.h"

ListIteratorFactory ListIteratorFactory::listIterFactory;

ListIteratorFactory::ListIteratorFactory()
{
    IteratorFactory::_register("List", this);
}

Iterator *ListIteratorFactory::createIterator()
{
    return new NullIterator();
}

Iterator *ListIteratorFactory::createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end)
{
    return new ListCompoundIterator<list<Shape *>::iterator>(begin, end);
}