#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

//Friends: Friend functions/methods
class Settings
{
private:
	int windowWidth, windowHeight, volumeLevel;

public:
	Settings() {}
	
	int getWindowWidth() const { return windowWidth; }
	int getWindowHeight() const { return windowHeight; }
	int getVolumeLevel() const { return volumeLevel; }

	//Friends: Friend functions/methods
	//friend void loadSettings(Settings &settings); // Declaration of a friend function that is outside the class.
	friend class SettingsLoader; //Declaration of a friend class that is outside this class.
};

//Friends: Friend functions/methods//Friends: Friend functions/methods
#if 0
void loadSettings(Settings &settings) //Declaration of the friend function. We pass an instance of the Settings class with which call the class.
{
	settings.windowWidth = 1920;
	settings.windowHeight = 1080;
	settings.volumeLevel = 10;
}
#endif

 //Friends: Friend classes
class SettingsLoader //Declaration of the friend class. 
{
public:
	SettingsLoader() {};
	
	void loadSettings(Settings &settings) //Declaration of the friend function. We pass an instance of the Settings class with which call the class.
	{
		settings.windowWidth = 1920;
		settings.windowHeight = 1080;
		settings.volumeLevel = 10;
	}
};

void ExamplesIV()
{
	Settings Set1;
	SettingsLoader Set2;

	Set2.loadSettings(Set1);
	cout << " " << Set1.getWindowWidth() << " " << Set1.getWindowHeight() << " " << Set1.getVolumeLevel();
}

class Item
{
private:
	char iName[64];

public:
	Item() {}
	Item(char * name)
	{
		strcpy_s(iName, name);
	}

	~Item() { cout << " The " << iName << " item was destroyed." << endl; }

	friend class Player;
};

class Player
{
private:
	char name[64];
	unsigned short lifes;
	bool invincible;
	bool * capabilities = new bool[3];
	bool * weapon = new bool[3];

public:
	Player(char * name) : lifes(3), invincible(false)
	{
		strcpy_s(this->name, name);
		
		for (int i = 0; i < 3; i++)
		{
			weapon[i] = false;

			if (i != 1)
			{
				capabilities[i] = false;
			}

			else
			{
				capabilities[i] = true;
			}
		}
	}

	~Player() { delete[] capabilities; delete[] weapon; }

	char * getName() { return name; } //If we havw char string[] as a data member, a function calling it has to be of the char* type.

	void PrintNumLifes() { cout << " " << lifes << endl; }
	void PrintInvincible() 
	{
		if (invincible)
		{
			cout << " The Player is invincible" << endl;
		}
		else
		{
			cout << " The Player is not invincible" << endl;
		}
	}

	void PrintCapabilities() 
	{
		for (int i = 0; i < 3; i++)
		{
			if (capabilities[i])
			{
				cout << " Capabilities[ " << i+1 << "] is set to true:" << endl;
			}
		}
	}

	void PrintWeapon()
	{
		for (int i = 0; i < 3; i++)
		{
			if (weapon[i])
			{
				cout << " Weapon[ " << i+1 << "] is set to true:" << endl;
			}
		}
	}

	bool charactersAreEqual(Player characterI, Player characterII)
	{
		if (strcmp(characterI.name, characterII.name) != 0)
		{
			cout << " " << characterI.name << " and " << characterII.name << " are the same character." << endl;
			return true;
		}

		else
		{
			cout << " " << characterI.name << " and " << characterII.name << " are not the same character." << endl;
			return false;
		}
	}

	void useItem(Item item)
	{
		if (strcmp(item.iName, "One_Up") != 0)
		{
			lifes++;
		}

		else if (strcmp(item.iName, "Super_Mario") != 0)
		{
			/*for (int i = 0; i < 2; i++)
			{
				if (capabilities[i])
				{
					capabilities[i + 1] = true;
					capabilities[i] = false;
				}
			}*/

			capabilities[2] = true;
			capabilities[1] = false;
			capabilities[0] = false;
		}

		else if (strcmp(item.iName, "Mini_Mario") != 0)
		{
			/*for (int i = 0; i < 3; i++)
			{
				if (capabilities[i])
				{
					capabilities[i - 1] = true;
					capabilities[i] = false;
				}
			}*/

			capabilities[0] = true;
			capabilities[1] = false;
			capabilities[2] = false;
		}

		if (strcmp(item.iName, "Fire_Flower") != 0)
		{
			weapon[0] = true;
			weapon[1] = false;
			weapon[2] = false;
		}

		else if (strcmp(item.iName, "Ice_Flower") != 0)
		{
			weapon[0] = false;
			weapon[1] = true;
			weapon[2] = false;
		}

		else if (strcmp(item.iName, "Golden_Flower") != 0)
		{
			weapon[0] = false;
			weapon[1] = false;
			weapon[2] = true;
		}
	}

	friend void starTouched(Player * p);
};

void starTouched(Player * plyr)
{
	plyr->invincible = true;
}

//Ex_I: Declaring variables and methods in the Player class.

//Ex_II: Declaring the Item class.

//Ex_III: Adding more methods/functions to the Player class using friendship (Item).

//Ex_IV: Implementing the starTouched() function through friendship with the Player class.

//Ex_V: Main Program
void Friendship_MarioBros()
{
	cout << "Introduce the name of the character: " << endl;
	char newName[32];
	cin >> newName;

	Player player(newName);

	cout << "Introduce the name of an item, 'Star' or 'Quit': " << endl;
	char newItem[32];
	cin >> newItem[32];

	while(strcmp(newItem, "Quit") == 0)
	{
		Item item(newItem);

		if (strcmp(newItem, "Super_Mario") != 0 || strcmp(newItem, "Mini_Mario") != 0 || strcmp(newItem, "Fire_Flower") != 0 || strcmp(newItem, "Ice_Flower") != 0 || strcmp(newItem, "Golden_Flower"))
		{
			player.useItem(item);
		}

		else if (strcmp(newItem, "Star") != 0)
		{
			starTouched(&player);
		}

		cout << "--- " << player.getName() << " ---" << endl;
		player.PrintNumLifes();
		player.PrintCapabilities();
		player.PrintInvincible();
		player.PrintWeapon();

		cout << " Introduce the name of an Item, 'Star' or 'Quit'." << endl;
		cin >> newName;
	}
}