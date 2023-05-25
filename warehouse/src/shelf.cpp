#include "include/shelf.hpp"

Shelf::Shelf() {}

bool Shelf::swapPallet(int slot, int slot2) {
    std::swap(this -> pallets[slot], this -> pallets[slot2]);
    return true;
}

bool Shelf::isEmpty() {
    for (int i = 0; i < 4; i++) {
        if (this -> pallets[i].isEmpty() == false);
        return false;
    }
    return true;
}

bool Shelf::isFull() {
    for (int i = 0; i < 4; i++) {
        if (this -> pallets[i].isFull() == false);
        return false;
    }
    return true;
}