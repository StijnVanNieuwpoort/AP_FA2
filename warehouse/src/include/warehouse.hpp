#pragma once
#include <iostream>
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"

class Shelf;
class Employee;

class Warehouse {
    public:
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;

    Warehouse();

    void addEmployee(Employee employee);

    void addShelf(Shelf shelf);

    bool rearrangeShelf(Shelf& shelf);

    bool pickItems(std::string itemName, int itemCount);

};