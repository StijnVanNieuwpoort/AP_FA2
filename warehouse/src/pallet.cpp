#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {
    this -> itemName = itemName;
    this -> itemCapacity = itemCapacity;
    this -> itemCount = itemCount;
}

Pallet::Pallet() {
    this -> itemCount = 0;
}

std::string Pallet::getItemName() {
    return this -> itemName;
}

int Pallet::getItemCount() {
    return this -> itemCount;
}

int Pallet::getRemainingSpace() {
    return this -> itemCapacity - this -> itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    if (this -> itemCount == 0) {
        this -> itemName = itemName;
        this -> itemCapacity = itemCapacity;
    }
    return false;
}

bool Pallet::takeOne() {
    if (this -> isEmpty() == false) {
        this -> itemCount -= 1;
        return true;
    }
    return false;
}

bool Pallet::putOne() {
    if (this -> isFull() == false) {
        this -> itemCount += 1;
        return true;
    }
    return false;
}

bool Pallet::isEmpty() {
    if (this -> itemCount == 0) {
        return true;
    }
    return false;
}

bool Pallet::isFull() {
     if (this -> itemCount == this -> itemCapacity) {
        return true;
     }
     return false;
}