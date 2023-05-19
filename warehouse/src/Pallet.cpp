#include "include/Pallet.hpp"

// Constructor
Pallet::Pallet(const std::string& itemName, int itemCapacity, int itemCount)
  : itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

// Default constructor
Pallet::Pallet() : itemCount(0), itemName(""), itemCapacity(0) {}


// Getter for itemName
std::string Pallet::getItemName() const {
  return itemName;
}

// Getter for itemCount
int Pallet::getItemCount() const {
  return itemCount;
}

// Getter for itemCapacity
int Pallet::getRemainingSpace() const {
  return itemCapacity - itemCount;
}

// Reallocate an empty pallet with a new item name and capacity.
bool Pallet::reallocateEmptyPallet(const std::string& newItemName, int newItemCapacity) {
  if (itemCount == 0) {
    itemName = newItemName;
    itemCapacity = newItemCapacity;
    return true;
  }
  return false;
}

// Take one item from the pallet.
bool Pallet::takeOne() {
  if (itemCount > 0) {
    itemCount--;
    return true;
  }
  return false;
}

// Put one item on the pallet.
bool Pallet::putOne() {
  if (itemCount < itemCapacity) {
    itemCount++;
    return true;
  }
  return false;
}

// IContainer methods
bool Pallet::isEmpty() const {
  return itemCount == 0;
}

bool Pallet::isFull() const {
  return itemCount == itemCapacity;
}
