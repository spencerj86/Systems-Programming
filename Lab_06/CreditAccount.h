#pragma once
#include "BaseAccount.h"
class CreditAccount :
	public BaseAccount
{
private:
	int amountSpent = 0;
public:
	void Withdrawl(float amount);
};

