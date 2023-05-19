#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    const string name;
    bool busy;
    bool forkliftCertificate;

public:
    Employee(const string& name, bool forkliftCertificate);

    string getName() const;
    bool getBusy() const;
    void setBusy(bool busy);
    bool getForkliftCertificate() const;
    void setForkliftCertificate(bool forkliftCertificate);
};

#endif // EMPLOYEE_H
