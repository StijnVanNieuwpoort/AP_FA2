#pragma once
#include <iostream>
#include <vector>

// Interface file with 2 virtual functions.
class Container {
    public:

    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
};