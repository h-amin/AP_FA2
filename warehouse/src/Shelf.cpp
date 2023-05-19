#include "src/include/Shelf.hpp"

// Constructor
Shelf::Shelf() {}

// IContainer methods
std::array<bool, 4> Shelf::getSlotStatus() const {
  std::array<bool, 4> statuses;
  for (size_t i = 0; i < pallets.size(); i++) {
    statuses[i] = !pallets[i].isEmpty();
  }
  return statuses;
}

// Remove a pallet from the shelf.
bool Shelf::removePallet(int slot) {
  if (slot >= 0 && slot < 4 && !pallets[slot].isEmpty()) {
    pallets[slot] = Pallet();
    return true;
  }
  return false;
}

// Insert a pallet into the shelf.
bool Shelf::insertPallet(int slot, const Pallet& pallet) {
  if (slot >= 0 && slot < 4 && pallets[slot].isEmpty()) {
    pallets[slot] = pallet;
    return true;
  }
  return false;
}

// Get a reference to a pallet
Pallet& Shelf::getPallet(int slot) {
  if (slot >= 0 && slot < 4) {
    return pallets[slot];
  }
  // Handle error case here if slot is out of bounds.
  throw std::out_of_range("Invalid slot number");
}

void Shelf::rearrangePallets() {
  std::sort(pallets.begin(), pallets.end(), [](const Pallet& a, const Pallet& b) {
    return a.getItemCount() < b.getItemCount();
  });
}

// IContainer methods
bool Shelf::isEmpty() const {
  for (const auto& pallet : pallets) {
    if (!pallet.isEmpty()) {
      return false;
    }
  }
  return true;
}

bool Shelf::isFull() const {
  for (const auto& pallet : pallets) {
    if (!pallet.isFull()) {
      return false;
    }
  }
  return true;
}