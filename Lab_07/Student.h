#pragma once
#include "Base.h"

class Student :
    public Base
{
    private:
        float GPA = 0;
    public:
        Student();
        ~Student();
        void SetGPA(float gpaInput);
        void DisplayRecord();
};

