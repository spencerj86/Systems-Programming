#include "CreditAccount.h"
#include <iostream>

void CreditAccount::Withdrawl(float amount)
{
    amountSpent += amount;
    if (amountSpent > 40)
    {
        std::cout << "You have overspent on your 40$ daily allowance, and will therefore be charged $5,000";
        amountSpent += 5000;
    }
    accountBalance -= amountSpent;
    //if reach 41$, charge 5000$ fee.
}
