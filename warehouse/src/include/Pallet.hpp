#ifndef PALLET_HPP
#define PALLET_HPP

#include <string>
#include "IContainer.hpp"

using namespace std;

class Pallet : public IContainer {
private:
  int itemCount;
  string itemName;
  int itemCapacity;

public:
  Pallet(const string& itemName, int itemCapacity, int itemCount);
  Pallet();

  string getItemName() const;
  int getItemCount() const;
  int getRemainingSpace() const;
  bool reallocateEmptyPallet(const string& newItemName, int newItemCapacity);
  bool takeOne();
  bool putOne();

  // IContainer methods
  bool isEmpty() const;
  bool isFull() const;
};

#endif // PALLET_HPP
