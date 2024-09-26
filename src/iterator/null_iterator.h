#pragma once

#include "iterator.h"

class NullIterator : public Iterator
{
public:
    void first() override {
        throw "No shape in list";
    }

    Shape* currentItem() const override {
        throw "No shape in list";
    }

    void next() override {
        throw "No shape in list";
    }

    bool isDone() const override {
        return true;
    }
};
