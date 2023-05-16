#ifndef SHELF_H
#define SHELF_H

#include <array>
#include "Pallet.hpp"
#include "IContainer.hpp"

class Pallet;

class Shelf : public IContainer {
public:
    std::array<Pallet, 4> pallets;

public:
    Shelf();

    bool swapPallet(int slot1, int slot2);

    bool isEmpty() const;
    bool isFull() const;
};

#endif // SHELF_H
