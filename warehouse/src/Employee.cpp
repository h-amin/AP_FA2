#include "src/include/Employee.hpp"

// Constructor
Employee::Employee(const std::string& name, bool forkliftCertificate)
    : name(name), busy(false), forkliftCertificate(forkliftCertificate) {}

// Getter for name
std::string Employee::getName() const {
    return name;
}

// Getter for busy
bool Employee::getBusy() const {
    return busy;
}

// Setter for busy
void Employee::setBusy(bool busy) {
    this->busy = busy;
}

// Getter for forkliftCertificate
bool Employee::getForkliftCertificate() const {
    return forkliftCertificate;
}

// Setter for forkliftCertificate
void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}
