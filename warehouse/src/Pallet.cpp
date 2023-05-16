#include "src/include/Pallet.hpp"

Pallet::Pallet(std::string itemName,
int itemCapacity, int itemCount)
: itemName(std::move(itemName)), itemCapacity(itemCapacity), itemCount(itemCount) {}

Pallet::Pallet()
: itemName(""), itemCapacity(0), itemCount(0) {}

std::string Pallet::getItemName() const {
return itemName;
}

int Pallet::getItemCount() const {
return itemCount;
}

int Pallet::getRemainingSpace() const {
return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
if (isEmpty()) {
this->itemName = std::move(itemName);
this->itemCapacity = itemCapacity;
return true;
}
return false;
}

bool Pallet::takeOne() {
if (!isEmpty()) {
itemCount--;
return true;
}
return false;
}

bool Pallet::putOne() {
if (!isFull()) {
itemCount++;
return true;
}
return false;
}

bool Pallet::isEmpty() const {
return itemCount == 0;
}

bool Pallet::isFull() const {
return itemCount == itemCapacity;
}