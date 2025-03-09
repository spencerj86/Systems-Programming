#include "CheckingAccount.h"
#include <iostream>

void CheckingAccount::Withdrawl(float amount)
{
    //override to enforce charging 5$ fee if withdrawlQuantity reaches 10.
    if (withdrawlQuantity >= 10)
    {
        std::cout << "You have exceeded the amount of weekly withdrawls, and will be charged $5.";
        accountBalance -= 5;
        accountBalance -= amount;
    }
    else
        BaseAccount::Withdrawl(amount);
}

