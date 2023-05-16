#include "src/include/Employee.hpp"

Employee::Employee(std::string name, bool forkliftCertificate)
    : name(std::move(name)), busy(false), forkliftCertificate(forkliftCertificate) {}

std::string Employee::getName() const {
    return name;
}

bool Employee::getBusy() const {
    return busy;
}

void Employee::setBusy(bool busy) {
    this->busy = busy;
}

bool Employee::getForkliftCertificate() const {
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}
