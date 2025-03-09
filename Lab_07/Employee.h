#pragma once
#include "Base.h"

class Employee :
    public Base
{
private:
    int salary = 0;
public:
    Employee();
    ~Employee();
    void SetSalary(int salaryInput);
    void DisplayRecord();
};

