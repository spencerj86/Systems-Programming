#include "BaseAccount.h"
#include <iostream>

void BaseAccount::Withdrawl(float amount)
{
	//decrease balance by amount
	accountBalance -= amount;
	//reduce balance and add 1 to withdrawlQuantity
	withdrawlQuantity++;
}
float BaseAccount::GetBalance() const
{
	return accountBalance;
}

void BaseAccount::Deposit(float amount)
{
	accountBalance += amount;
}
