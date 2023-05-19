#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <string>
#include "Employee.hpp"
#include "Shelf.hpp"

using namespace std;

class Warehouse {
public:
    vector<Employee> employees;
    vector<Shelf> shelves;

public:
    Warehouse();

    void addEmployee(const Employee& employee);
    void addShelf(const Shelf& shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(const string& itemName, int itemCount);   
};

#endif // WAREHOUSE_H
