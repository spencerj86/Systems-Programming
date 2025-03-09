#pragma once
#include <iostream>
#include <ctime>

void ClearInputBuffer(); int GetInteger(const char* prompt); int GetChoice(const char* prompt, const char* options[], int count);
char* GetString(const char* prompt, int size); int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange);

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
		std::cout << i << ". " << options[i] << "\n"; //prints to the console, i = number in array corresponding to the number
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

































































































































































































//this program was created for use by FullSail University and James Spencer exclusively. Any other use is fraudulent.