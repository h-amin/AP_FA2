#include "src/include/Warehouse.hpp"
#include <algorithm>

// Default constructor
Warehouse::Warehouse() {}

// Add an employee to the warehouse
void Warehouse::addEmployee(const Employee& employee) {
  employees.push_back(employee);
}

// Add a shelf to the warehouse
void Warehouse::addShelf(const Shelf& shelf) {
  shelves.push_back(shelf);
}

// Rearrange a shelf
bool Warehouse::rearrangeShelf(Shelf& shelf) {
  // Check if there's an available employee with a forklift certificate
  auto it = std::find_if(employees.begin(), employees.end(), [](const Employee& e) {
    return !e.getBusy() && e.getForkliftCertificate();
  });

  if (it == employees.end()) {
    return false;
  }

  it->setBusy(true);

  // Rearrange the shelf
  shelf.rearrangePallets();

  it->setBusy(false);

  return true;
}

// Pick items from the warehouse
bool Warehouse::pickItems(const std::string& itemName, int itemCount) {
  int count = 0;

  // Search through all shelves for the item
  for (auto& shelf : shelves) {
    // And all pallets on each shelf
    for (int i = 0; i < 4; i++) {
      // Find the target item
      auto& pallet = shelf.getPallet(i);
      if (pallet.getItemName() == itemName) {
        while (pallet.getItemCount() > 0 && count < itemCount) {
          if (pallet.takeOne()) {
            count++;
          }
        }
      }
    }
  }

  return count == itemCount;
}