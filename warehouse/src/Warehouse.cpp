#include "src/include/Warehouse.hpp"

Warehouse::Warehouse() {
    // Warehouse constructor implementation
}

void Warehouse::addEmployee(Employee employee) {
    employees.push_back(employee);
}

void Warehouse::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf, const Employee& employee) {
    if (!employee.getForkliftCertificate()) {
        return false;
    }

    if (shelf.isEmpty() || shelf.isFull()) {
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3 - i; ++j) {
            if (shelf.swapPallet(j, j + 1)) {
                // Pallets swapped successfully
            } else {
                // Failed to swap pallets
            }
        }
    }

    return true;
}

bool Warehouse::pickItems(const std::string& itemName, int itemCount) {
    int remainingItems = itemCount;
    for (auto& shelf : shelves) {
        for (auto& pallet : shelf.pallets) {
            if (pallet.getItemName() == itemName) {
                while (remainingItems > 0 && !pallet.isEmpty()) {
                    if (pallet.takeOne()) {
                        remainingItems--;
                    } else {
                        break;
                    }
                }
            }
            if (remainingItems == 0) {
                return true;
            }
        }
    }
    return false;
}
