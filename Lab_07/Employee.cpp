#include "Employee.h"
#include <iostream>

Employee::Employee() : salary(0)
{

}
Employee::~Employee()
{
    salary = 0;
}
void Employee::DisplayRecord()
{
    std::cout << "Employee's Name: " << GetName() << std::endl;
    std::cout << "Employee's Salary: " << salary << std::endl;
}

void Employee::SetSalary(int salaryInput)
{
    salary = salaryInput;
}
