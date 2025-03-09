#include "Base.h"

Base::Base()
{

}

Base::~Base()
{

}

Base& Base::operator=(const Base& other)
{
	if (this != &other)
		CopyString(other.GetName(), name);

	return *this;
}