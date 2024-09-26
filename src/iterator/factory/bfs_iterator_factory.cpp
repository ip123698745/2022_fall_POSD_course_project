#include "./bfs_iterator_factory.h"
#include "../null_iterator.h"
#include "../bfs_compound_iterator.h"

BFSIteratorFactory BFSIteratorFactory::bfsIterFactory;

BFSIteratorFactory::BFSIteratorFactory()
{
    IteratorFactory::_register("BFS", this);
}

Iterator *BFSIteratorFactory::createIterator()
{
    return new NullIterator();
}

Iterator *BFSIteratorFactory::createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end)
{
    return new BFSCompoundIterator<list<Shape *>::iterator>(begin, end);
}