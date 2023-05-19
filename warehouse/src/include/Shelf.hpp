#ifndef SHELF_HPP
#define SHELF_HPP

#include <array>
#include "Pallet.hpp"
#include "IContainer.hpp"

using namespace std;

class Shelf : public IContainer {
public:
  array<Pallet, 4> pallets;

public:
  Shelf();

  array<bool, 4> getSlotStatus() const;
  bool removePallet(int slot);
  bool insertPallet(int slot, const Pallet& pallet);

  Pallet& getPallet(int slot);  // new method, for getting a reference to a pallet
  void rearrangePallets();      // new method, for rearranging pallets on the shelf

  // IContainer methods
  bool isEmpty() const;
  bool isFull() const;
};

#endif // SHELF_HPP
