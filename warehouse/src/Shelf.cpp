#include "src/include/Shelf.hpp"

Shelf::Shelf() {
    for (auto& pallet : pallets) {
        pallet = Pallet();
    }
}

bool Shelf::swapPallet(int slot1, int slot2) {
    if (slot1 >= 0 && slot1 < 4 && slot2 >= 0 && slot2 < 4) {
        std::swap(pallets[slot1], pallets[slot2]);
        return true;
    }
    return false;
}

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
