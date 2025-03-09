#include <vector>
#include <iostream>
#include "Base.h"
#include "Employee.h"
#include "Student.h"

void ClearInputBuffer();
int GetInteger(const char* prompt);
int GetChoice(const char* prompt, const char* options[], int count);
char* GetString(const char* prompt, int size);
int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange);
void CopyString(const char* source, char*& destination);
float GetFloat(const char* prompt);

std::vector<Base*> people;
void AddRecord(); void DisplayRecords(); void DuplicateRecord();

int main()
{
	const char* options[] = { "Add Record" , "Display Record" , "Duplicate Record" , "Exit" };
	bool menu = true;
	while (menu)
	{
		system("cls");
		int selection = GetChoice("Select One: ", options, 4);
		switch (selection)
		{
		case 1:
			AddRecord();
			break;
		case 2:
			DisplayRecords();
			break;
		case 3:
			DuplicateRecord();
			break;
		case 4:
			menu = false;
			break;
		}
		system("pause");
	}
	for (size_t i = 0; i < people.size(); i++)
	{
		delete people[i];
	}
}

void AddRecord()
{
	const char* recordOptions[] = { "Employee" , "Student" , "Exit" };
	bool recordMenu = true;
	int Salary;
	float gpa;
	Student* s;
	Employee* e;
	while (recordMenu)
	{
		system("cls");
		char* name = GetString("What's the name? ", 32);
		int recordSelection = GetChoice("Select: ", recordOptions, 3);
		switch (recordSelection)
		{
		case 1:
			e = new Employee();
			e->SetName(name);
			Salary = GetInteger("What's their yearly salary? ");
			e->SetSalary(Salary);
			people.push_back(e);
			//delete e;
			break;
		case 2:
			s = new Student();
			s->SetName(name);
			gpa = GetFloat("What's the student's GPA? ");
			s->SetGPA(gpa);
			people.push_back(s);
			//delete s;
			break;
		case 3:
			recordMenu = false;
			break;
		}
	}

}

void DisplayRecords()
{
	for (size_t i = 0; i < people.size(); i++)
	{
		people[i]->DisplayRecord();
	}
}

void DuplicateRecord()
{
	int userInt = GetInteger("Select an index to duplicate! ");
	Employee* _employee = dynamic_cast<Employee*>(people[userInt]);
	Student* _student = dynamic_cast<Student*>(people[userInt]);

	if (_employee != nullptr)
	{
		Employee* r = new Employee(*_employee);
		people.push_back(r);
	}
	else if (_student != nullptr)
	{
		Student* d = new Student(*_student); // my logic
		people.push_back(d);
	}
}

void ClearInputBuffer()
{
	std::cin.clear(); //clear the input buffer ...
	std::cin.ignore(INT_MAX, '\n'); //will ignore input buffers until reaching \n ...
}

int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange)
{
	int response = 0;
	while (true)
	{
		std::cout << strMessage;
		if (std::cin >> response)
		{
			if (nMinimumRange > 0 && nMaximumRange > 0)
			{
				if (response >= nMinimumRange && response <= nMaximumRange)
				{
					ClearInputBuffer();
					return response;
				}
				else
				{
					std::cout << "\nInvalid Response. Must be between " << nMinimumRange << " and " << nMaximumRange << "\n";
					ClearInputBuffer();
				}
			}
			else
			{
				ClearInputBuffer();
				return response;
			}
		}
		std::cout << "\n Invalid Response. Please Try Again: ";
		ClearInputBuffer();
	}
}

int GetInteger(const char* prompt) //when calling this function, you must type in the message in which you are passing
//through to the integer.
{
	int number = 0; //this will set number to 0, to initialize the integer ...
	while (true) // this will run until the number returns as a confirmed integer ...
	{
		std::cout << prompt; //display your words passed in through the function ...
		if (std::cin >> number) //checking if the input received from the user is a number ...
		{
			ClearInputBuffer(); //clears input buffer, to make further input reception possible ...
			return number; //gives confirmed number to program ...
		}
		ClearInputBuffer(); //clears input buffer, before error message, this makes it possible for more input ...
		std::cout << "\n Invalid Response. Please Try Again: "; //error message, will loop on this until integer is confirmed ...
	}
}

int GetChoice(const char* prompt, const char* options[], int count) //this is a menu code
//const char prompt is the same example as in GetInteger
//const char* options is an array of options that must be put in through the function, you can cast an enum to this method
//example : const char* options[] = {"Red", "Blue", "Green", "Black" };
//example : carArray[i].Color = (EnumColorDefinition)(GetChoice("Select Color: ", options, 4)
//This makes a menu of 4 choices, that takes the enum to create the choices and makes your menu.
//the options array is what you print, and the enum holds the value for which you are having user select ...
{
	for (size_t i = 0; i < count; i++) //basic for loop man... cmon.
	{
		std::cout << i+1 << ". " << options[i] << "\n"; //prints to the console, i = number in array corresponding to the number
		//needed to be pressed.
	}
	int selection = GetInteger(prompt); //calling the GetInteger method, passing in prompt from GetChoice, no need to do this process
	//again ...
	return selection;
}

char* GetString(const char* prompt, int size)
{
	char* result = new char[size];
	std::cout << prompt;
	while (true)
	{
		std::cin.getline(result, size);
		if (result != "" || result != NULL)
		{
			return result;
		}

		std::cout << "\nPlease enter a VALID string.\n\n";
	}
}

void setData(const char* input, char* data) // char* data is required in the class you'll be calling this method for
//remove char* data from this function and place it in the class you'll be using it for. ex: char* name = nullptr;
{
	//figure out how many chars in input + 1 for null terminator
	int length = strlen(input) + 1;
	//new char[] of that size - data
	data = new char[length];
	//copy input to data
	strcpy_s(data, length, input);
}

void CopyString(const char* source, char*& destination) //taken from lab, not your code!
{
	delete[] destination;
	int length = strlen(source) + 1;
	strcpy_s(destination, length, source);
}

float GetFloat(const char* prompt) //when calling this function, you must type in the message in which you are passing
//through to the integer.
{
	float number = 0; //this will set number to 0, to initialize the integer ...
	while (true) // this will run until the number returns as a confirmed integer ...
	{
		std::cout << prompt; //display your words passed in through the function ...
		if (std::cin >> number) //checking if the input received from the user is a number ...
		{
			ClearInputBuffer(); //clears input buffer, to make further input reception possible ...
			return number; //gives confirmed number to program ...
		}
		ClearInputBuffer(); //clears input buffer, before error message, this makes it possible for more input ...
		std::cout << "\n Invalid Response. Please Try Again: "; //error message, will loop on this until integer is confirmed ...
	}
}