#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "pallet.hpp"
#include "container.hpp"

class Pallet;

class Shelf : public Container {
    public:
    std::array<Pallet, 4> pallets;

    Shelf();

    bool swapPallet(int slot, int slot2);
};