#include "src/include/Warehouse.hpp"
#include <iostream>

int main() {
    // Create a warehouse
    Warehouse warehouse;

    // Add employees
    Employee employee1("John", true);
    Employee employee2("Alice", false);
    warehouse.addEmployee(employee1);
    warehouse.addEmployee(employee2);

    // Add shelves
    Shelf shelf1;
    Shelf shelf2;
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    // Perform operations
    Employee& john = warehouse.employees[0];
    Shelf& shelf = warehouse.shelves[0];

    if (warehouse.rearrangeShelf(shelf, john)) {
        std::cout << "Shelf rearranged successfully by John." << std::endl;
    } else {
        std::cout << "Shelf rearrangement failed." << std::endl;
    }

    if (warehouse.pickItems("itemA", 5)) {
        std::cout << "Items picked successfully." << std::endl;
    } else {
        std::cout << "Failed to pick items." << std::endl;
    }

    return 0;
}

