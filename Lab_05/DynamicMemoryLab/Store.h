#pragma once
#include <vector>
#include "Register.h"

class Store {
private:
	std::vector<Register*> _registers;
public:
	Store();
	long long GetReceipts();
};