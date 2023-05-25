#pragma once
#include <iostream>
#include <vector>
#include "container.hpp"

class Pallet : public Container {
    private:
    int itemCount;
    std::string itemName;
    int itemCapacity;

    public:
    Pallet(std::string itemName, int itemCapacity, int itemCount);
    Pallet();

    std::string getItemName();
    int getItemCount();
    
    int getRemainingSpace();

    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);

    bool takeOne();
    bool putOne();
};