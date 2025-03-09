#pragma once
#include <iostream>

class Base
{
	//SetName must do a deep copy of the memory, since it's name is a dynamic pointer
	//CopyString?

	//implement Rule of 3 for the class since it has a dynamic memory member
	//constructor
	//destructor
	//copy business
	//you only need to write the operator = and just have your copy constructor call that method (*this = copy)
private:
	char* name = nullptr;
public:
	virtual void DisplayRecord() = 0;
	Base();
	~Base();
	Base& operator=(const Base&);
	void SetName(char* nameInput)
	{
		CopyString(nameInput, name);
	}
	const char* GetName() const { return name; }

	void CopyString(const char* source, char*& destination) //taken from lab, not your code!
	{
		delete[] destination;
		int length = strlen(source) + 1;
		destination = new char[length];
		strcpy_s(destination, length, source);
	}
};

