#include <iostream>
#include <stdlib.h>
#include <ctime>
void ProgramOneOne(), ProgramOneTwo(), ProgramOneThree(), ProgramOneFour(), ProgramOneFive(), ProgramOneSix(), ProgramOneSeven(),
ProgramOneEight(), ProgramOneNine(), ProgramOneTen();
void ClearInputBuffer();
int GetInteger(const char* prompt);
enum PopsilceChoice;
enum Difficulty;

int main()
{
	srand(unsigned int(time(NULL)));
	ProgramOneOne();
	ProgramOneTwo();
	ProgramOneThree();
	ProgramOneFour();
	ProgramOneFive();
	ProgramOneSix();
	ProgramOneSeven();
	ProgramOneEight();
	ProgramOneNine();
	ProgramOneTen();
}

void ProgramOneOne()
{
	std::cout << "------------------------------------ Program 1-1 ------------------------------------\n";
	char name[32];
	std::cout << "Hello Stranger! Can I have your initials please? \n\n"; //standard name space :: console output >>
	std::cin.get(name, 32); //takes name from the input buffer and places it into the name variable, with a maximum character possible 32.
	ClearInputBuffer();
	int age = GetInteger("\nAnd how old are you? ");
	std::cout << "\n\nAccepted. Character Profile initiated for " << name << ".  Age is set to approximately " << age * 365 << " days.\n\n\n";
}

void ProgramOneTwo()
{
	std::cout << "------------------------------------ Program 1-2 ------------------------------------\n";
	int num[5];
	for (size_t i = 0; i < 5; i++)
	{
		num[i] = GetInteger("Please enter a number: ");
	}
	std::cout << "You entered: ";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << num[i];
	}
	std::cout << "\n\n\n";
}

void ProgramOneThree()
{
	std::cout << "------------------------------------ Program 1-3 ------------------------------------\n";
	int a = GetInteger("Enter value for 'a': ");
	int b = GetInteger("Enter value for 'b': ");
	int c = GetInteger("Enter value for 'c': ");
	std::cout << " a + 1  *  b + 2  - c = " << a + 1 * b + 2 - c << "\n";
	std::cout << "(a + 1) * (b + 2) - c = " << (a + 1) * (b + 2) - c << "\n\n\n";
}

void ProgramOneFour()
{
	std::cout << "------------------------------------ Program 1-4 ------------------------------------\n";
	std::cout << "   ushort:  " << "0" << " to " << USHRT_MAX << "\n";
	std::cout << "    short:  " << SHRT_MIN << " to " << SHRT_MAX << "\n";
	std::cout << "     uint:  " << "0" << " to " << UINT_MAX << "\n";
	std::cout << "      int:  " << INT_MIN << " to " << INT_MAX << "\n";
	std::cout << "    ulong:  " << "0" << " to " << ULONG_MAX << "\n";
	std::cout << "     long:  " << LONG_MIN << " to " << LONG_MAX << "\n";
	std::cout << "ulonglong:  " << "0" << " to " << ULLONG_MAX << "\n";
	std::cout << " longlong:  " << LLONG_MIN << " to " << ULLONG_MAX << "\n\n\n";
}

void ProgramOneFive()
{
	std::cout << "------------------------------------ Program 1-5 ------------------------------------\n";
	char name[32];
	std::cout << "What's your name, friend?\n";
	std::cin.getline(name, 32);
	std::cout << "Well, " << name << ", Did you know that the longest stretch of time between twins being born is 87 days? ...Yikes.\n\n\n";
}
void ProgramOneSix()
{
	std::cout << "------------------------------------ Program 1-6 ------------------------------------\n";
	int age = GetInteger("How old are you again?\n");
	if (age < 18)
	{
		std::cout << "You're too young to be here...\n";
		exit(3);
	}
	else
	{
		std::cout << "Did you know that more French soldiers died during World War 1 than American soldiers during all of U.S. history?\n";
		std::cout << "The French lost approximately 1,360,000 soldiers in World War 1 alone.\n";
		std::cout << "Whereas the United States has lost approximately 1,350,000 throughout all of it's wars since 1775.\n\n\n";
	}
}
void ProgramOneSeven()
{
	std::cout << "------------------------------------ Program 1-7 ------------------------------------\n";
	while (true)
	{
		int number = GetInteger("Please Enter An Even Number: ");
		if (number % 2 == 0)
		{
			std::cout << "Yeah! That's correct!";
			break;
		}
		else
		{
			std::cout << "Nah, that's not right, try again. \n";
		}
	}
}
void ProgramOneEight()
{
	std::cout << "\n\n\n------------------------------------ Program 1-8 ------------------------------------\n";
	int number = GetInteger("Please enter a number, and I'll try to stick it into these random numbers to see if it is divisible.\n");
	for (size_t i = 0; i < 3; i++)
	{
		int test = rand();
		std::cout << test << "\t- ";
		if (test % number == 0)
		{
			std::cout << "YES!";
		}
		else
		{
			std::cout << "Nah...";
		}
		std::cout << "\n\n\n";
	}
}
void ProgramOneNine()
{
	std::cout << "------------------------------------ Program 1-9 ------------------------------------\n";
	enum PopsicleChoice { Black, Red, Green, Blue, a , b , c , d , e , f , g , h , i , Orange};
	int menuChoice;
	std::cout << "1. Red\n2. Green\n3. Blue\n13.Orange\n";
	std::cout << "Select a Popsicle!\n";
	std::cin >> menuChoice;
	switch (menuChoice)
	{
	case Red:
		std::cout << "Ah, Cherry. Great choice. +1 for goodness!";
		break;
	case Green:
		std::cout << "Green Apple! That's alright too! Gotta love the sours!";
		break;
	case Blue:
		std::cout << "Blue Raspberry... Still good, not great! But no judgement for that one.";
		break;
	case Orange:
		std::cout << "Orange...? Really? Orange... Alright, I guess.";
		break;
	}
	std::cout << "\n\n\n";
}
void ProgramOneTen()
{
	enum Difficulty { null, Easy, Hard, Extreme };
	int choice;
	std::cout << "1.Easy\n2.Hard\n3. EXTREME!\n";
	std::cout << "Select Difficulty!";
	std::cin >> choice;
	switch (choice)
	{
	case Easy:
	{
		int easy = (rand() % 5);
		std::cout << easy << " enemies appeared.";
		break;
	}
	case Hard:
	{
		int hard = (rand() % 20);
		std::cout << hard << " enemies appeared.";
		break;
	}
	case Extreme:
	{
		int extreme = (rand() % 100);
		std::cout << extreme << " enemies appeared.";
		break;
	}
	std::cout << "\n\n\n";
	}
}

int GetChoice(const char* prompt, const char* options[])
{
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << options[i];
	}
	int selection = GetInteger(prompt);
	return selection;
}

int GetInteger(const char* prompt)
{
	int number = 0;
	while (true)
	{
		std::cout << prompt;

		if (std::cin >> number)
		{
			return number;
			ClearInputBuffer();
		}
		ClearInputBuffer();
		std::cout << "\n Invalid Response. Try again.";
	}
	
}

void ClearInputBuffer()
{
	std::cin.clear();//clears input buffer
	std::cin.ignore(INT_MAX, '\n');//will ignore input buffers until reaching \n
}




//int ReadInteger(int min, int max)
