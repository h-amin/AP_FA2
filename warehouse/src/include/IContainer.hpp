#ifndef ICONTAINER_H
#define ICONTAINER_H

class IContainer {
public:
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};

#endif // ICONTAINER_H