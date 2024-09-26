#include "./dfs_iterator_factory.h"
#include "../dfs_compound_iterator.h"
#include "../null_iterator.h"

DFSIteratorFactory DFSIteratorFactory::dfsIterFactory;

DFSIteratorFactory::DFSIteratorFactory()
{
    IteratorFactory::_register("DFS", this);
}

Iterator *DFSIteratorFactory::createIterator()
{
    return new NullIterator();
}

Iterator *DFSIteratorFactory::createIterator(list<Shape *>::iterator begin, list<Shape *>::iterator end)
{
    return new DFSCompoundIterator<list<Shape *>::iterator>(begin, end);
}