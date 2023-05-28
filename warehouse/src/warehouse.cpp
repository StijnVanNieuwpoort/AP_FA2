#include "include/warehouse.hpp"

// Constructor
Warehouse::Warehouse() {}

void Warehouse::addEmployee(Employee employee) {
    this -> employees.push_back(employee);
}

// Adds an additional shelf to the shelves vector.
void Warehouse::addShelf(Shelf shelf) {
    this -> shelves.push_back(shelf);
}

// Organizes pallets in a shelf based on the itemCount of pallets in ascending order.
// This funtion does not succeed, if there is no available employee with a forklift certificate.
bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Loops through employees, if an employee is not busy (employee.getBusy() == false) and has a forklift certificate (employee.getForkliftCertificate() == true)
    // The qualified var will become true.
    bool qualified = false;
    for (Employee employee : employees) {
        if (employee.getBusy() == false && employee.getForkliftCertificate() == true) {
            qualified = true;
        }
    }

    // If qualified equals true, the pallets in the shelf will be sorted by principle of bubblesort.
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

// Function with args: itemName and itemCount.
// Removes 'itemCount' amount of items from pallets in warehouse where 'itemName'.
bool Warehouse::pickItems(std::string itemName, int itemCount) {
    // Counts number of items in warehouse that equal itemName.
    int numberOfItems = 0;
    for (Shelf shelf : this -> shelves) {
        for (Pallet pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                numberOfItems += pallet.getItemCount();
            }
        }
    }

    // If numberOfItems is bigger than or equals 'itemCount', items from pallets equal to 'itemName' get removed using pallet.takeOne().
    // This happens 'itemCount' number of times. Will completely empty a pallet before moving on to the next one until 'itemCount' iterations are reached.
    if (numberOfItems >= itemCount) {
        int check = 0;
        for (Shelf& shelf : this -> shelves) {
            for (Pallet& pallet : shelf.pallets) {
                if (pallet.getItemName() == itemName) {
                    for (int i = 0; i < pallet.getItemCount(); i++) {
                        pallet.takeOne();
                        check += 1;
                        if (check == itemCount) {
                            return true;
                        }
                    }
                }
            }
        }
        return true;
    }
   

    return false;
}