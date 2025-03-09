#include "SavingsAccount.h"
#include <iostream>

void SavingsAccount::Withdrawl(float amount)
{
    //do not allow more than 3 withdrawls from this account.
    withdrawlQuantity++;
    if (withdrawlQuantity <= 3)
    {
        accountBalance -= amount;
    }
    else
    {
        std::cout << "You have reached the withdrawl limit for this account.";
    }
}
