#include "include/warehouse.hpp"

Warehouse::Warehouse() {}

void Warehouse::addEmployee(Employee employee) {
    this -> employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    this -> shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    bool qualified = false;
    for (Employee employee : employees) {
        if (employee.getBusy() == false && employee.getForkliftCertificate() == true) {
            qualified = true;
        }
    }

    while (qualified) {
        bool swapped = false;
        for (int i = 1; i < 4; i++) {
            if (shelf.pallets[i-1].getItemCount() > shelf.pallets[i].getItemCount()) {
                if (shelf.swapPallet(i-1, i)) {
                    swapped = true;
                }
            }
        }
        if (swapped == false) {
            break;
        }
    }
    return qualified;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    int numberOfItems = 0;
    for (Shelf shelf : this -> shelves) {
        for (Pallet pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                numberOfItems += pallet.getItemCount();
            }
        }
    }

    if (numberOfItems > itemCount) {
        while (numberOfItems == 0) {
            for (Shelf shelf : this -> shelves) {
                for (Pallet pallet : shelf.pallets) {
                    pallet.takeOne();
                    numberOfItems -= 1;
                }
            }
        }
        return true;
    }

    return false;
}