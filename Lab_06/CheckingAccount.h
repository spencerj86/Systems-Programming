#pragma once
#include "BaseAccount.h"
class CheckingAccount :
    public BaseAccount
{
public:
    void Withdrawl(float amount);
};

