#include <iostream>
#include <vector>
#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <fstream>
void ClearInputBuffer();
int GetInteger(const char* prompt), GetChoice(const char* prompt, const char* options[], int count);
char* GetString(const char* prompt, int size);


int main()
{
	CheckingAccount checkingAccount;
	SavingsAccount savingsAccount;
	CreditAccount creditAccount;
	int amount = 0;

	std::ifstream fin;
	fin.open("output.txt");
	if (fin.is_open())
	{
		int balance;
		fin >> balance;
		checkingAccount.Deposit(balance);
		fin >> balance;
		savingsAccount.Deposit(balance);
		fin >> balance;
		creditAccount.Deposit(balance);
		fin.close();
	}
	else
	{
		checkingAccount.Deposit(1200);
		savingsAccount.Deposit(2500);
		creditAccount.Deposit(25000);
	}

	const char* options[] = { "Checking","Savings","Credit" , "Exit" };
	const char* savingsOptions[] = { "View Balance " , "Withdrawl" , "Deposit" };
	const char* checkingOptions[] = { "View Balance " , "Withdrawl" , "Deposit" };
	const char* creditOptions[] = { "View Balance" , "Spend Credit" , "Make Payment" };
	int selection = NULL;
	int checkingSelection = NULL;
	int savingsSelection = NULL;
	int creditSelection = NULL;
	bool menu = true;

	while (menu)
	{
		selection = GetChoice("Which account would you like to view? ", options, 4);
		switch (selection)
		{
		case 0:
			checkingSelection = GetChoice("Select an option ", checkingOptions, 3);
			switch (checkingSelection)
			{
			case 0:
				std::cout << "Checking Account Balance: $" << checkingAccount.GetBalance() << std::endl;
				break;
			case 1:
				amount = GetInteger("Withdrawl how much? ");
				checkingAccount.Withdrawl(amount);
				std::cout << "\nChecking Balance Remaining: $" << checkingAccount.GetBalance() << std::endl;
				void ClearInputBuffer();
				break;
			case 2:
				amount = GetInteger("Deposit how much into Checking? ");
				checkingAccount.Deposit(amount);
				std::cout << "\nChecking Balance Updated: $" << checkingAccount.GetBalance() << std::endl;
				void ClearInputBuffer();
				break;
			}
			break;
		case 1:
			savingsSelection = GetChoice("Select an option ", savingsOptions, 3);
			switch (savingsSelection)
			{
			case 0:
				std::cout << "Savings Account Balance: $" << savingsAccount.GetBalance() << std::endl;
				break;
			case 1:
				amount = GetInteger("Withdrawl how much from Savings? ");
				savingsAccount.Withdrawl(amount);
				std::cout << "\nSavings Balance Remaining: $" << savingsAccount.GetBalance() << std::endl;
				void ClearInputBuffer();
				break;
			case 2:
				amount = GetInteger("Deposit how much? ");
				savingsAccount.Deposit(amount);
				std::cout << "\nSavings Balance Updated: $" << savingsAccount.GetBalance() << std::endl;
				void ClearInputBuffer();
				break;
			}
			break;
		case 2:
			creditSelection = GetChoice("Select an option ", creditOptions, 3);
			switch (creditSelection)
			{
			case 0:
				std::cout << "Credit Account Balance: $" << creditAccount.GetBalance() << std::endl;
				break;
			case 1:
				amount = GetInteger("Spend how much on credit? ");
				creditAccount.Withdrawl(amount);
				std::cout << "\nCredit Remaining: $" << creditAccount.GetBalance() << std::endl;
				void ClearInputBuffer();
				break;
			case 2:
				amount = GetInteger("Pay off how much? ");
				creditAccount.Deposit(amount);
				std::cout << "\nCredit Amount Updated: $" << creditAccount.GetBalance() << std::endl;
				void ClearInputBuffer();
				break;
			}
			break;
		case 3:
			menu = false;
			break;
		}
	}
	std::ofstream myFileStream;
	myFileStream.open("output.txt");
	myFileStream << checkingAccount.GetBalance() << std::endl;
	myFileStream << savingsAccount.GetBalance() << std::endl;
	myFileStream << creditAccount.GetBalance() << std::endl;
	myFileStream.close();
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

void ClearInputBuffer()
{
	std::cin.clear(); //clear the input buffer ...
	std::cin.ignore(INT_MAX, '\n'); //will ignore input buffers until reaching \n ...
}