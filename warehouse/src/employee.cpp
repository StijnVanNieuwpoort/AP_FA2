#include "include/employee.hpp"

// Constructor
Employee::Employee(std::string name, bool forkliftCertificate) {
    this -> name = name;
    this -> forkliftCertificate = forkliftCertificate;
}

// Getters and setters.
std::string Employee::getName() {
    return this -> name;
}

bool Employee::getBusy() {
    return this -> busy;
}

void Employee::setBusy(bool busy) {
    this -> busy = busy;
}

bool Employee::getForkliftCertificate() {
    return this -> forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this -> forkliftCertificate = forkliftCertificate;
}