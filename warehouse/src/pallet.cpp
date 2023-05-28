#include "include/pallet.hpp"

// Constructor with args.
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {
    this -> itemName = itemName;
    this -> itemCapacity = itemCapacity;
    this -> itemCount = itemCount;
}

// Constructor without args.
Pallet::Pallet() {
    this -> itemCount = 0;
}

// Getters
std::string Pallet::getItemName() {
    return this -> itemName;
}

int Pallet::getItemCount() {
    return this -> itemCount;
}

int Pallet::getRemainingSpace() {
    return this -> itemCapacity - this -> itemCount;
}

// This function redesignates a pallet when it's itemCount is equal to zero (empty pallet).
bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    if (this -> itemCount == 0) {
        this -> itemName = itemName;
        this -> itemCapacity = itemCapacity;
    }
    return false;
}

// Reduces itemCount of this Pallet by 1, unless the pallet is empty.
bool Pallet::takeOne() {
    if (this -> isEmpty() == false) {
        this -> itemCount = itemCount - 1;
        return true;
    }
    return false;
}

// Increases itemCount of this Pallet by 1, unless the pallet is full.
bool Pallet::putOne() {
    if (this -> isFull() == false) {
        this -> itemCount += 1;
        return true;
    }
    return false;
}

// Inherited function from the container interface class.
// Checks if a pallet is full. A pallet is full when it's itemCount equals 0.
bool Pallet::isEmpty() {
    if (this -> itemCount < 1) {
        return true;
    }
    return false;
}

// Inherited function from the container interface class.
// Checks if a pallet is full. A pallet is full when it's itemCount equals it's itemCapacity.
bool Pallet::isFull() {
     if (this -> itemCount == this -> itemCapacity) {
        return true;
     }
     return false;
}