#include <iostream>
#include "src/include/Warehouse.hpp"
#include "src/include/Shelf.hpp"
#include "src/include/Pallet.hpp"
#include "src/include/Employee.hpp"


int main() {
  // Create warehouse
  Warehouse warehouse;

  // Create and add employees
  Employee john("John", true); // John has a forklift certificate
  Employee sarah("Sarah", false); // Sarah doesn't have a forklift certificate

  warehouse.addEmployee(john);
  warehouse.addEmployee(sarah);

  // Create and add shelves with pallets
  Shelf shelf1, shelf2;

  Pallet pallet1("Item1", 10, 5);
  Pallet pallet2("Item2", 15, 10);
  Pallet pallet3("Item3", 20, 15);

  shelf1.insertPallet(0, pallet1);
  shelf1.insertPallet(1, pallet2);
  shelf2.insertPallet(0, pallet3);

  warehouse.addShelf(shelf1);
  warehouse.addShelf(shelf2);

  // Try to rearrange shelf1
  if (warehouse.rearrangeShelf(shelf1)) {
    std::cout << "Shelf1 rearranged successfully.\n";
  } else {
    std::cout << "Shelf1 rearrangement failed.\n";
  }

  // Try to pick items
  if (warehouse.pickItems("Item1", 2)) {
    std::cout << "Picked 2 of Item1 successfully.\n";
  } else {
    std::cout << "Failed to pick 2 of Item1.\n";
  }

  if (warehouse.pickItems("Item2", 11)) {
    std::cout << "Picked 11 of Item2 successfully.\n";
  } else {
    std::cout << "Failed to pick 11 of Item2.\n";
  }

  return 0;
}
