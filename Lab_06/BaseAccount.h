#pragma once
class BaseAccount
{
protected:
	float accountBalance = 0;
	int withdrawlQuantity = 0;
public:
	void Withdrawl(float amount);
	float GetBalance() const;
	void Deposit(float amount);
};

