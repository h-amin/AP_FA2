#ifndef PALLET_H
#define PALLET_H

#include <string>

class Pallet {
private:
    int itemCount;
    std::string itemName;
    int itemCapacity;

public:
    Pallet(std::string itemName, int itemCapacity, int itemCount);
    Pallet();

    std::string getItemName() const;
    int getItemCount() const;
    int getRemainingSpace() const;

    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();

    bool isEmpty() const;
    bool isFull() const;
};

#endif // PALLET_H
