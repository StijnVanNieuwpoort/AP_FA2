#include "include/shelf.hpp"

// Constructor
Shelf::Shelf() {
    this -> pallets = {Pallet(), Pallet(), Pallet(), Pallet()};
}

// Swaps the memory location of two pallets in the pallets array using the swap() function.
bool Shelf::swapPallet(int slot, int slot2) {
    std::swap(this -> pallets[slot], this -> pallets[slot2]);
    return true;
}

// Inherited function from the container interface class.
// Checks if a shelf is empty. A shelf is empty when all 4 pallets in it, are empty.
bool Shelf::isEmpty() {
    for (int i = 0; i < 4; i++) {
        if (this -> pallets[i].isEmpty() == false);
        return false;
    }
    return true;
}

// Inherited function from the container interface class.
// Checks if a shelf is full. A shelf is full when all 4 pallets in it, are full.
bool Shelf::isFull() {
    for (int i = 0; i < 4; i++) {
        if (this -> pallets[i].isFull() == false);
        return false;
    }
    return true;
}