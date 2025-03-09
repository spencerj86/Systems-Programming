#include <iostream>
#include "Helper.h"

int main()
{
	while (true)
	{
		const char* options[] = { "Compliment","Insult","Fact","Fiction","Name entry"};
		int selection = GetChoice("Choose what you would like to do.\n", options, 5);
		switch (selection)
		{
		case 0:
			std::cout << "You're a very effective person.";
			break;
		case 1:
			std::cout << "You're ability to comprehend extraterrestrial existance is primitive!";
			break;
		case 2:
			std::cout << "Glaciers and ice sheets hold about 69 percent of the world's freshwater.";
			break;
		case 3:
			std::cout << "Life is easy peasy. Tragedy is the work of the illuminati to keep the masses docile.";
			break;
		case 4:
			const char* input = GetString("Please enter your name! ", 32);
			std::cout << input << " is correct! Good name dude(ette)!";
		}
		std::cout << "\n";
	}
}

//helper library assignment
//create a menu code that is useable elsewhere
//implement +GetChoice and +Get Integers for the menu code, also useable elsewhere
//add GetString method to library
//must be sure to implement pointers to practice
//need to add one more thing, preferably challenging, ideas to follow:
//