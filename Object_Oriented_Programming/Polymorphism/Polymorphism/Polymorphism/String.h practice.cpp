#include <string.h>
#include <iostream>

void string()
{
	char name[64];

	char name2[64];

	//name = "Pepe" //Doesn't work.
	//if (name == "Pepe"){} //Doesn't work either.

	strcpy_s(name, "Pepe"); //Assigns a string to a char array.

	if (strcmp(name, "Pepe") == 0)
	{
		std::cout << "Ma boy is the same :weary::ok_sign:" << std::endl;
	}
}