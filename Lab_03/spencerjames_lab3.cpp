#include <iostream>
#include <ctime>
enum class EnumColorDefinition { Red, Blue, Green, Black };
struct Car
{
	char* Make;
	char* Model;
	int Year;
	int mileage;
	EnumColorDefinition Color;
};
void repaintCar(Car* ptrCar, EnumColorDefinition newcolor)
{
	ptrCar->Color = newcolor;
}
void printCar(Car c);
void printCarPointer(Car* ptrCar);

void addMileage(Car* ptrCar, int milestoadd)
{
	ptrCar->mileage += milestoadd;
}
void memAddress(int x, int* y);
int GetChoice(const char* prompt, const char* options[], int count);
int GetInteger(const char* prompt);void ClearInputBuffer();
char* GetString(const char* prompt, int size);
void ProgramOne();
void ProgramTwo();
void ProgramThree();

int main()
{
	ProgramOne();
	std::cout << "-----------------------------------------------\n\n";
	ProgramTwo();
	std::cout << "-----------------------------------------------\n\n";
	ProgramThree();

	//changeValue(x);
}

void ProgramOne()
{
	srand(unsigned int(time(NULL)));
	int numArray[15];
	const int arraySize = 15;
	for (size_t i = 0; i < arraySize; i++)
	{
		numArray[i] = rand();
	}
	for (size_t i = 0; i < arraySize; i++)
	{
		std::cout << numArray[i] << " is located at " << &numArray[i] << " memory address." << std::endl;
	}
}

void ProgramTwo()
{
	srand(unsigned int(time(NULL)));
	int numArray[15];
	const int arraySize = 15;
	for (size_t i = 0; i < arraySize; i++)
	{
		numArray[i] = rand();
	}
	for (size_t i = 0; i < arraySize; i++)
	{
		memAddress(numArray[i], &numArray[i]);
	}
}

void ProgramThree()
{
	Car* carArray = new Car[3];
	for (size_t ndx = 0; ndx < 3; ndx++)
	{
		std::cout << "We're making cars today! Please enter the forthcoming information!\n\n";
		carArray[ndx].Make = GetString("Make: ", 32);
		carArray[ndx].Model = GetString("Model: ", 32);
		carArray[ndx].Year = GetInteger("Year: ");
		carArray[ndx].mileage = GetInteger("Mileage: ");
		const char* options[] = { "Red", "Blue", "Green", "Black" };
		carArray[ndx].Color = (EnumColorDefinition)(GetChoice("Select Color: ", options, 4));
		std::cout << "\n\n";
	}

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "-------------STANDARD-------------";
		printCar(carArray[i]);
		std::cout << "-------------POINTER-------------";
		printCarPointer(&carArray[i]);
		std::cout << "---------------------------------\n";
	}
	int carChoice = GetInteger("Pick a number: 0, 1, or 2.\n");
	int colorChoice = GetInteger("0: red\n1:Blue\n2:Green\n3:Black\n");
	repaintCar(&carArray[carChoice], (EnumColorDefinition)colorChoice);
	printCarPointer(&carArray[carChoice]);

	int carChoice2 = GetInteger("Pick a number: 0, 1, 2. \n");
	int miles = GetInteger("Add how many miles? ");
	addMileage(&carArray[carChoice2], miles);
	printCarPointer(&carArray[carChoice2]);
	
	delete[] carArray;
}

void printCar(Car c)
{
	std::cout << "\n" << c.Year << " ";
	switch (c.Color)
	{
	case EnumColorDefinition::Red:
		std::cout << "Red";
		break;
	case EnumColorDefinition::Blue:
		std::cout << "Blue";
		break;
	case EnumColorDefinition::Green:
		std::cout << "Green";
		break;
	case EnumColorDefinition::Black:
		std::cout << "Black";
		break;
	}
	std::cout << " " << c.Make <<
		" " << c.Model << " with " << c.mileage << " miles.\n\n";
}

void printCarPointer(Car* ptrCar)
{
	std::cout << "\n" << ptrCar->Year << " ";
	switch (ptrCar->Color)
	{
	case EnumColorDefinition::Red:
		std::cout << "Red";
		break;
	case EnumColorDefinition::Blue:
		std::cout << "Blue";
		break;
	case EnumColorDefinition::Green:
		std::cout << "Green";
		break;
	case EnumColorDefinition::Black:
		std::cout << "Black";
		break;
	}
	std::cout << " " << ptrCar->Make <<
		" " << ptrCar->Model << " with " << ptrCar->mileage << " miles.\n\n";
}



void memAddress(int x, int* y)
{
	std::cout << x << " is located at " << y << " memory address." << std::endl;
}

void ClearInputBuffer()
{
	std::cin.clear();//clears input buffer
	std::cin.ignore(INT_MAX, '\n');//will ignore input buffers until reaching \n
}

int GetInteger(const char* prompt)
{
	int number = 0;
	while (true)
	{
		std::cout << prompt;

		if (std::cin >> number)
		{
			ClearInputBuffer();
			return number;
		}
		ClearInputBuffer();
		std::cout << "\n Invalid Response. Try again.";
	}
}

int GetChoice(const char* prompt, const char* options[], int count)
{
	for (size_t i = 0; i < count; i++)
	{
		std::cout << i << ". " << options[i] << "\n";
	}
	int selection = GetInteger(prompt);
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