#include "Student.h"
#include <iostream>

Student::Student() : GPA(0)
{

}
Student::~Student()
{
    GPA = 0;
}
void Student::DisplayRecord()
{
    std::cout << "Student's Name: " << GetName() << std::endl;
    std::cout << "Student's GPA: " << GPA << std::endl;
}

void Student::SetGPA(float gpaInput)
{
    GPA = gpaInput;
}
