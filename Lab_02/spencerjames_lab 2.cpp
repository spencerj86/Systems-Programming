
#include <iostream>
#include <bitset>
#include <stdlib.h>

void ClearInputBuffer();
int GetInteger(const char* prompt, int min, int max);
int GetChoice(const char* prompt, const char* options[]);
void printBinaryNumber(unsigned int number, int size);
void TurnOn(int bit); void TurnOff(int bit); void Toggle(int bit); void Negate(); void LeftShift(); void RightShift();
unsigned int bitField = 0;
const int bitSize = 32;


int main()
{
	while (true)
	{
		system("cls");
		printBinaryNumber(bitField, bitSize);
		const char* options[] = { "TurnOn", "TurnOff", "Toggle", "Negate", "LeftShift", "Right Shift" , "Quit" };
		int selection = GetChoice("Choose: ", options);
		switch (selection)
		{
		case 1:
			TurnOn(GetInteger("Which index? ", 0, 31));
			break;
		case 2:
			TurnOff(GetInteger("Which index? ", 0, 31));
			break;
		case 3:
			Toggle(GetInteger("Which index? ", 0, 31));
			break;
		case 4:
			Negate();
			break;
		case 5:
			LeftShift();
			break;
		case 6:
			RightShift();
			break;
		case 7:
			exit(3);
			break;
		}
	}


	/*unsigned char myValue1 = 149;
	unsigned char myValue2 = 63;

	std::cout << "Decimal: " << (int(myValue1)) << std::endl;
	std::cout << "BinaryL " << std::bitset<8>(myValue1) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int)myValue1 << std::endl;
	std::cout << "\nleft shift\n";
	std::cout << "Decimal: " << std::dec << (int(myValue1 << 1)) << std::endl;
	std::cout << "Binary: " << std::bitset<8>(int(myValue1 << 1)) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int(myValue1 << 1)) << std::endl;
	std::cout << "\nright shift\n";
	std::cout << "Decimal: " << std::dec << (int(myValue1 >> 2)) << std::endl;
	std::cout << "Binary: " << std::bitset<8>((myValue1 >> 2)) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int(myValue1 >> 2)) << std::endl;
	std::cout << "\nNOT\n";
	std::cout << "Decimal: " << std::dec << (int(~myValue1)) << std::endl;
	std::cout << "Binary: " << std::bitset<8>(int(~myValue1)) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int(~myValue1)) << std::endl;
	std::cout << "\nAND\n";
	std::cout << "Decimal: " << std::dec << (int(myValue1 & myValue2)) << std::endl;
	std::cout << "Binary: " << std::bitset<8>(int(myValue1 & myValue2)) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int(myValue1 & myValue2)) << std::endl;
	std::cout << "\nOR\n";
	std::cout << "Decimal: " << std::dec << (int(myValue1 | myValue2)) << std::endl;
	std::cout << "Binary: " << std::bitset<8>(int(myValue1 | myValue2)) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int(myValue1 | myValue2)) << std::endl;
	std::cout << "\nXOR\n";
	std::cout << "Decimal: " << std::dec << (int(myValue1 ^ myValue2)) << std::endl;
	std::cout << "Binary: " << std::bitset<8>(int(myValue1 ^ myValue2)) << std::endl;
	std::cout << "Hexadecimal " << std::hex << (int(myValue1 ^ myValue2)) << std::endl;*/
}

void TurnOn(int bit)
{
	bitField |= (1 << bit);
}

void TurnOff(int bit)
{
	bitField &= ~(1 << bit);
}

void Toggle(int bit)
{
	bitField ^= (1 << bit);
}

void Negate()
{
	bitField = ~bitField;
}
void LeftShift()
{
	bitField <<= 1;
}
void RightShift()
{
	bitField >>= 1;
}
void printBinaryNumber(unsigned int number, int size) //printBinaryNumber(bitField)
{
	char* text = new char[size + 1];
	text[size] = '\0';
	for (int i = size - 1; i >= 0; i--)
	{
		//check least significant bit for 1 | 0, put in array at spot
		if ((number % 2) == 0)
		{
			text[i] = '0';
		}
		else
		{
			text[i] = '1';
		}
		number >>= 1;
		// 1101
		// aaa!
		// aa!a >>
		// xaa!
	}
	std::cout << text << "\n";
	delete[] text;
}

int GetChoice(const char* prompt, const char* options[])
{
	for (unsigned int i = 1; i < sizeof(options); i++)
	{
		std::cout << i << ". " << options[i - 1] << " \n";
	}
	int selection = GetInteger(prompt, 1, sizeof(options) - 1);
	return selection;
}

int GetInteger(const char* prompt, int min, int max)
{
	int number = 0;
	while (true)
	{
		std::cout << prompt;

		if (std::cin >> number && number >= min && number <= max)
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