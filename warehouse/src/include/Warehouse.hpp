#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include "Employee.hpp"
#include "Shelf.hpp"

class Warehouse {
public:
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;

public:
    Warehouse();

    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf, const Employee& employee);
    bool pickItems(const std::string& itemName, int itemCount);
};

#endif // WAREHOUSE_H
