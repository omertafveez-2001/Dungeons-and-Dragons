// Libraries
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <chrono>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>  // for srand and rand
#include <string>

using namespace std;

// Heroes Arrays.
// Array[4] = {strike, counter, intelligence, health}
int human_fighter[4] = { 16, 20, 16, 100 };
int halfelf_fighter[4] = { 19, 14, 14, 100 };
int woodelf_fighter[4] = { 12, 10, 17, 100 };
int halfing_rogue[4] = { 14, 7, 15 , 100 };
int human_druid[4] = { 14, 10, 15, 100 };
int halfelf_wizard[4] = { 18, 12, 25, 100 };
int dwarf_cleric[4] = { 10, 15, 19, 100 };
int human_cleric[4] = { 6, 12, 15, 100 };

// Villians Arrays.
// orcs[2] = {strike, health}
int orcs[2] = { 12, 45 };

// giant orcs[2] = {strike, counter, health}
int giant_orcs[3] = { 18, 12, 80 };

// Boss Villians
int fraazurbloo[3] = { 50, 30, 1500 };

// for txt file
int saving_unit = 0;
int arr1[4];
int arr2[4];
int arr3[4];
int arr4[4];

// input for selecting options 
int input_story;

// input variables for choosing characters from the menu.
int user_1;
int user_2;
int user_3;
int user_4;


//pointers pointing to heroes arrays
int* user1 = NULL;
int* user2 = NULL;
int* user3 = NULL;
int* user4 = NULL;

// characters name
string hero1;
string hero2;
string hero3;
string hero4;


int* chosen_hero = NULL;
int decinc;
int acquired_gold;

// currency quantity
int gold = 100;

// variables that will effect the values stored in arrays of characters.
int health;
int strike;

void characterAttributes(int* user1, int temp);

int randFunction1()
{
	srand(time(NULL));
	int random_character = rand() % 4 + 1;
	return random_character;
}

int randFunction2()
{
	srand(time(NULL));
	int random_consequence = rand() % 2 + 1;
	return random_consequence;
}

void saveFile(int* user1, int* user2, int* user3, int* user4)
{
	fstream my_file;
	my_file.open("Dungoens and Dragons.txt", ios::out | ios::trunc);
	if (!my_file) {
		ofstream my_file("Dungoens and Dragons.txt");
	}
	fstream file;
	file.open("Dungoens and Dragons2.txt", ios::out | ios::trunc);
	if (!file) {
		ofstream file("Dungoens and Dragons2.txt");
	}
	for (int i = 0; i < 4; i++)
	{
		my_file << user1[i] << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		my_file << user2[i] << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		my_file << user3[i] << endl;
	}

	for (int i = 0; i < 4; i++)
	{
		my_file << user4[i] << endl;
	}
	my_file << saving_unit << endl;
	my_file.close();
	file << hero1 << endl;
	file << hero2 << endl;
	file << hero3 << endl;
	file << hero4;
	file.close();
}

void openFile()
{
	fstream my_file;
	my_file.open("Dungoens and Dragons.txt", ios::in);
	fstream file;
	file.open("Dungoens and Dragons2.txt", ios::in);
	string line;
	int number;
	for (int i = 0; i < 4; i++)
	{
		static int a = 0;
		my_file >> number;
		arr1[a] = number;
		a++;
	}

	for (int i = 4; i < 8; i++)
	{
		static int a = 0;
		my_file >> number;
		arr2[a] = number;
		a++;
	}

	for (int i = 8; i < 12; i++)
	{
		static int a = 0;
		my_file >> number;
		arr3[a] = number;
		a++;
	}

	for (int i = 12; i < 16; i++)
	{
		static int a = 0;
		my_file >> number;
		arr4[a] = number;
		a++;
	}

	for (int i = 16; i < 17; i++)
	{
		my_file >> number;
		saving_unit = number;
	}
	my_file.close();

	for (int i = 0; getline(file, line) && i < 4; i++)
	{
		if (i == 0)
		{
			hero1 = line;
		}
		else if (i == 1)
		{
			hero2 = line;
		}
		else if (i == 2)
		{
			hero3 = line;
		}
		else if (i == 3)
		{
			hero4 = line;
		}
	}
	file.close();
}

void charactersName()   // Character's List
{
	cout << left;
	cout << setw(18) << "Name" << setw(12) << "Strike" << setw(13) << "Defence" << setw(11) << setw(18) << "Intelligence" << setw(5) << "Special Attributes" << endl << endl;
	cout << setw(18) << "Human Fighter" << setw(12) << "16" << setw(13) << "20" << setw(11) << setw(18) << "16" << setw(5) << "Charge Shot - strike: 21" << endl << endl;
	cout << setw(18) << "Half-Elf Fighter" << setw(12) << "19" << setw(13) << "14" << setw(11) << setw(18) << "14" << setw(5) << "Atheletic Kill - strike: 26" << endl << endl;
	cout << setw(18) << "Wood-Elf Ranger" << setw(12) << "12" << setw(13) << "10" << setw(11) << setw(18) << "17" << setw(5) << "Blazin Kill - Strike: 30" << endl << endl;
	cout << setw(18) << "Halfing Rogue" << setw(12) << "14" << setw(13) << "7" << setw(11) << setw(18) << "15" << setw(5) << "Dual Weaponattack - Strike: 28" << endl << endl;
	cout << setw(18) << "Human Druid" << setw(12) << "14" << setw(13) << "10" << setw(11) << setw(18) << "15" << setw(5) << "Heal - Health: 15%" << endl;
	cout << right << setw(83) << "SuperNova - Strike: 44" << endl << endl;
	cout << left;
	cout << setw(18) << "Half-Elf Wizard" << setw(12) << "18" << setw(13) << "12" << setw(11) << setw(18) << "25" << setw(5) << "Sherlocked - Reveals Everything" << endl;
	cout << right << setw(88) << "Spell Modifier - Strike: 38" << endl << endl;
	cout << left;
	cout << setw(18) << "Dwarf Cleric" << setw(12) << "10" << setw(13) << "15" << setw(11) << setw(18) << "19" << setw(5) << "Health Potion - 15% increase" << endl << endl;
	cout << setw(18) << "Human Cleric" << setw(12) << "6" << setw(13) << "12" << setw(11) << setw(18) << "15" << setw(5) << "Health Potion - 30% increase" << endl;
	cout << right << setw(88) << "Thor's Thunder - Strike: 36" << endl;
}


void storyStage1(int* user1, int* user2, int* user3, int* user4)
{
	saving_unit++;
	string stage1 = hero1 + " , " + hero2 + " , " + hero3 + " , " + "and " + hero4 + " reached the gates of Hell, swirling through the portal. Blood and Lava erupted\nthrough the walls, dripping into the lake of Blood.\n"
		"All they could remember was the last words of Dungeon Master who said:\n\nEvery action has a consequence.\n"
		"Could this mean there is no coming back from Hell? Wondered Hero1. Hero2 took the lead and opened the giant door,\nthe coldness of fear swept through their spines as he opened the door.\n"
		"Dark cumulonimbus encapsulated the castle of Fraazurbloo. As they entered inside, they saw a small, vicious, green creature. ORC!\n"
		"Hero2 takes his stance and takes his sword out and decided to wipe out its existence but was halted by Hero4.\n"
		"They soon gathered behind the rock and decided their strategy. The first strategy was selecting the hero who could kill him.";
	cout << "\t\t\t\t\t\tLevel 1: The Devil Realm" << endl << endl;

	for (int i = 0; i < stage1.length(); i++)
	{
		cout << stage1[i];
		Sleep(30);
	}

	cout << endl;

	int random = randFunction1();
	int random_option = randFunction2();

	cout << endl;
	cout << hero1 + " Strength:        Strike: " << user1[0] << "   " << "Counter: " << user1[1] << "   " << "Intelligence: " << user1[2] << "   " << "Health: " << user1[3] << endl;
	cout << hero2 + " Strength:        Strike: " << user2[0] << "   " << "Counter: " << user2[1] << "   " << "Intelligence: " << user2[2] << "   " << "Health: " << user2[3] << endl;
	cout << hero3 + " Strength:        Strike: " << user3[0] << "   " << "Counter: " << user3[1] << "   " << "Intelligence: " << user3[2] << "   " << "Health: " << user3[3] << endl;
	cout << hero4 + " Strength:        Strike: " << user4[0] << "   " << "Counter: " << user4[1] << "   " << "Intelligence: " << user4[2] << "   " << "Health: " << user4[3] << endl << endl;
	if (random == 1)
	{
		cout << "It\'s " << hero1 << "\'s turn." << endl;
		chosen_hero = user1;
	}

	else if (random == 2)
	{
		cout << "It\'s " << hero2 << "\'s turn." << endl;
		chosen_hero = user2;
	}
	else if (random == 3)
	{
		cout << "It\'s " << hero3 << "\'s turn." << endl;
		chosen_hero = user3;
	}
	else
	{
		cout << "It\'s " << hero4 << "\'s turn." << endl << endl;
		chosen_hero = user4;
	}

	cout << endl;
	cout << "They come up with two decision.\n1) Chop the Orc\'s head and kill him.\n2) Sneak past the Orc." << endl << endl;
	cout << "Choose wisely" << endl << endl;
	cout << "Option: ";
	char ch = _getch();

	if (ch == '1')
	{
		if (random_option == 1)
		{
			cout << "Hero Kills the Orc and throws his body deep into the valley." << endl;
		}
		else
		{
			cout << "Orc counters and bit his hand. He throws a grenade and injures the hand. However, Orc is killed at the end." << endl;
			health = orcs[1];
			decinc = 0;
			characterAttributes(chosen_hero, 0);
			cout << endl << endl << endl;
			cout << "Your health decreased by 45!" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		}
	}

	else if (ch == '2')
	{
		cout << "The heroes successfully sneak past the orc and enter the valley of death. " << endl;
	}

	system("pause");
	system("cls");
	saveFile(user1, user2, user3, user4);
}

void storyStage2(int* user1, int* user2, int* user3, int* user4)
{
	chosen_hero = NULL;
	openFile();
	user1 = arr1;
	user2 = arr2;
	user3 = arr3;
	user4 = arr4;
	saving_unit++;
	string stage2 = "They looked closely at the orc and found some gold laying around his body. They went down the alley and picked up the loot.\n"
		"While they were busy picking up the loot, they heard someone.\n\nRevamp until you last! Revamp until you last!.\n\nThey picked 25 gold coins and started to move towards him.\n"
		"At a closer glance, it was a goldsmith.\nGoldsmith, Aye, what are you looking for? I have multiple upgraded weapons.\n\n";

	cout << "\t\t\t\t\t\tLevel 2: GoldSmith" << endl << endl;

	for (int i = 0; i < stage2.length(); i++)
	{
		cout << stage2[i];
		Sleep(30);
	}

	cout << endl;
	acquired_gold = 25;
	gold = 75;
	int random = randFunction1();
	int random_option = randFunction2();

	cout << hero1 + " Strength:        Strike: " << user1[0] << "   " << "Counter: " << user1[1] << "   " << "Intelligence: " << user1[2] << "   " << "Health: " << user1[3] << endl;
	cout << hero2 + " Strength:        Strike: " << user2[0] << "   " << "Counter: " << user2[1] << "   " << "Intelligence: " << user2[2] << "   " << "Health: " << user2[3] << endl;
	cout << hero3 + " Strength:        Strike: " << user3[0] << "   " << "Counter: " << user3[1] << "   " << "Intelligence: " << user3[2] << "   " << "Health: " << user3[3] << endl;
	cout << hero4 + " Strength:        Strike: " << user4[0] << "   " << "Counter: " << user4[1] << "   " << "Intelligence: " << user4[2] << "   " << "Health: " << user4[3] << endl << endl;

	if (random == 1)
	{
		cout << "It\'s " << hero1 << "\'s turn." << endl;
		chosen_hero = user1;
	}

	else if (random == 2)
	{
		cout << "It\'s " << hero2 << "\'s turn." << endl;
		chosen_hero = user2;
	}
	else if (random == 3)
	{
		cout << "It\'s " << hero3 << "\'s turn." << endl;
		chosen_hero = user3;
	}
	else
	{
		cout << "It\'s " << hero4 << "\'s turn." << endl << endl;
		chosen_hero = user4;
	}

	cout << "Shop Items.\n1) Upgraded Sword - 10 Gold Coin\n2) Upgraded Sword - 15 Gold Coins\n3) Increase Health - 25 Gold Coins" << endl << endl;
	cout << "Choose wisely" << endl << endl;
	cout << "Option: ";
	char ch = _getch();

	if (ch == '1')
	{
		decinc = 1;
		strike = 15;
		characterAttributes(chosen_hero, 0);
		acquired_gold = 15;
		cout << endl << endl << endl;
		cout << "Your Strike increased by 15!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}
	else if (ch == '2')
	{
		decinc = 1;
		strike = 20;
		characterAttributes(chosen_hero, 0);
		acquired_gold = 10;
		cout << endl << endl << endl;
		cout << "Your Strike increased by 20!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}
	else if (ch == '3')
	{
		decinc = 1;
		health = 15;
		characterAttributes(chosen_hero, 0);
		acquired_gold = 0;
		cout << endl << endl << endl;
		cout << "Your Health increased by 15!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}
	system("pause");
	saveFile(user1, user2, user3, user4);
}

void storyStage3(int* user1, int* user2, int* user3, int* user4)
{
	chosen_hero = NULL;
	openFile();
	user1 = arr1;
	user2 = arr2;
	user3 = arr3;
	user4 = arr4;
	saving_unit++;
	int random_option = randFunction2();

	string stage3 = "Began the journey to the mountain of terror, which the heroes thought was just a bridge that could lead them to the castle of Demogorgon.\nWhat they did not know was the fortified security of orcs surrounded by boulders and huge rocks. Settling through the barren surface of the land,\nthey reached the golden gate, almost 8km from the entrance of the bridge. The Golden Gate was guarded by 3 orcs.\n\nNot be fought alone this time.";
	cout << "\t\t\t\t\t\tLevel 3: The Golden Gate" << endl << endl;

	for (int i = 0; i < stage3.length(); i++)
	{
		cout << stage3[i];
		Sleep(30);
	}
	cout << endl;
	cout << hero1 + " Strength:        Strike: " << user1[0] << "   " << "Counter: " << user1[1] << "   " << "Intelligence: " << user1[2] << "   " << "Health: " << user1[3] << endl;
	cout << hero2 + " Strength:        Strike: " << user2[0] << "   " << "Counter: " << user2[1] << "   " << "Intelligence: " << user2[2] << "   " << "Health: " << user2[3] << endl;
	cout << hero3 + " Strength:        Strike: " << user3[0] << "   " << "Counter: " << user3[1] << "   " << "Intelligence: " << user3[2] << "   " << "Health: " << user3[3] << endl;
	cout << hero4 + " Strength:        Strike: " << user4[0] << "   " << "Counter: " << user4[1] << "   " << "Intelligence: " << user4[2] << "   " << "Health: " << user4[3] << endl << endl;

	cout << endl << "1. Target the orcs one at a time.\n2. Ambush the Orcs altogether" << endl;
	cout << "Option: ";
	char ch = _getch();

	if (ch == '1')
	{
		if (random_option == 1)
		{
			chosen_hero = user3;
			decinc = 0;
			health = 30;
			characterAttributes(chosen_hero, 0);
			cout << hero3 << " loses an arm. The heroes struggle but win the battle.";
			cout << endl << endl << endl;
			cout << "Your Health Decreased by 30!" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		}
		else
		{
			chosen_hero = user1;
			decinc = 0;
			health = 30;
			cout << hero1 << " and " << hero2 << " take a hit on head and bleed out. The battle resulted in a victory" << endl;
			characterAttributes(chosen_hero, 0);
			cout << "Your Health Decreased by 30" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
			chosen_hero = user2;
			characterAttributes(chosen_hero, 0);
			cout << endl << endl << endl;
			cout << "Your Health Decreased by 30" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		}
	}
	else
	{
		cout << "The ambush stunned the orcs, leaving heroes undefeated." << endl;
	}
	system("pause");
	saveFile(user1, user2, user3, user4);
}

void storyStage4(int* user1, int* user2, int* user3, int* user4)
{
	chosen_hero = NULL;
	int random = randFunction1();
	openFile();
	user1 = arr1;
	user2 = arr2;
	user3 = arr3;
	user4 = arr4;
	saving_unit++;
	string stage4 = "Blood dripped down the walls. Red and Green blood. Hero4 looked at the gold laying around orcs. To him, it looked important.\nBut were collecting gold coins actually important? If it\'s " + hero4 + " you can collect 50 gold coins.\nIf it\'s not, you cannot collect gold coins.\n\nIt all depends on luck.";
	cout << "\t\t\t\t\t\tLevel 4: Welcome Back" << endl << endl;

	for (int i = 0; i < stage4.length(); i++)
	{
		cout << stage4[i];
		Sleep(30);
	}
	cout << endl;
	cout << hero1 + " Strength:        Strike: " << user1[0] << "   " << "Counter: " << user1[1] << "   " << "Intelligence: " << user1[2] << "   " << "Health: " << user1[3] << endl;
	cout << hero2 + " Strength:        Strike: " << user2[0] << "   " << "Counter: " << user2[1] << "   " << "Intelligence: " << user2[2] << "   " << "Health: " << user2[3] << endl;
	cout << hero3 + " Strength:        Strike: " << user3[0] << "   " << "Counter: " << user3[1] << "   " << "Intelligence: " << user3[2] << "   " << "Health: " << user3[3] << endl;
	cout << hero4 + " Strength:        Strike: " << user4[0] << "   " << "Counter: " << user4[1] << "   " << "Intelligence: " << user4[2] << "   " << "Health: " << user4[3] << endl << endl;

	if (random == 1)
	{
		cout << "It\'s " << hero1 << "\'s turn." << endl;
		chosen_hero = user1;
		cout << endl << hero1 + " leaves all the gold coins behind." << endl;
		acquired_gold = 0;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}

	else if (random == 2)
	{
		cout << "It\'s " << hero2 << "\'s turn." << endl;
		chosen_hero = user2;
		cout << endl << hero2 + " leaves all the gold coins behind." << endl;
		acquired_gold = 0;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}
	else if (random == 3)
	{
		cout << "It\'s " << hero3 << "\'s turn." << endl;
		chosen_hero = user3;
		cout << endl << hero3 + " leaves all the gold coins behind." << endl;
		acquired_gold = 0;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}
	else
	{
		cout << "It\'s " << hero4 << "\'s turn." << endl << endl;
		chosen_hero = user4;
		cout << endl << hero4 + " takes 50 gold" << endl;
		acquired_gold = 50;
		cout << "Acquired Gold: " << acquired_gold << endl;
	}

	stage4 = "Bleeding, staggering, they start running towards the gate. As they were running towards the bridge, they saw the same goldsmith.\nIt felt eerie. Nevertheless, they needed to restore something.\nThe goldsmith looked at them and said:\nAye!! Welcome back! What ya need from my store?";

	for (int i = 0; i < stage4.length(); i++)
	{
		cout << stage4[i];
		Sleep(30);
	}
	cout << endl;
	cout << "1) Upgraded Sword - 40 Gold Coins\n2) Increase Health - 50 Gold Coins\n3) Exit the Shop" << endl << endl;
	cout << "Current Gold: " << acquired_gold << endl;
	cout << "Choose Wisely" << endl;
	cout << "Option: ";
	char ch = _getch();

	if (ch == '1')
	{
		if (chosen_hero == user4)
		{
			decinc = 1;
			strike = 40;
			characterAttributes(chosen_hero, 0);
			cout << "Your Strike Increased by 40!" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		}
		else
		{
			cout << "Not enough Gold" << endl;
		}
	}
	else if (ch == '2')
	{
		if (chosen_hero == user4)
		{
			decinc = 1;
			health = 30;
			characterAttributes(chosen_hero, 0);
			cout << "Your Health Increased by 30!" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		}
		else
		{
			cout << "Not enough Gold" << endl;
		}
	}
	else
	{

	}
	system("pause");
	saveFile(user1, user2, user3, user4);
}

void storyStage5(int* user1, int* user2, int* user3, int* user4)
{
	chosen_hero = NULL;
	int random_option = randFunction2();
	openFile();
	user1 = arr1;
	user2 = arr2;
	user3 = arr3;
	user4 = arr4;
	saving_unit++;
	string stage5 = "Skulls laying everywhere. One could smell the fear and the blood of the fallen soldiers. Lay forward a bridge made of skulls.\nThe Heroes could hear the souls of the fallen soldiers crying and weeping. The Heroes seeing this did not fear as they were sent for a purpose.\nA purpose to save humanity. Lay before them two bridges. One extending to the left, and one to the right. The Heros should decide which path shall they take.";
	cout << "\t\t\t\t\t\tLevel 5: Hell Bridge" << endl << endl;

	for (int i = 0; i < stage5.length(); i++)
	{
		cout << stage5[i];
		Sleep(30);
	}

	cout << endl << "1. Choose to go right.\n2. Choose to go left" << endl;
	cout << "Option: ";
	char ch = _getch();

	if (ch == '1')
	{
		cout << endl << "Two Orcs take a glance at you and rush towards you. What do you do?" << endl;
		cout << "1. Fight the Orcs and Kill them.\n2. Escape the Orcs." << endl;
		cout << "Option: ";
		ch = _getch();
		random_option = randFunction2();

		if (ch == '1')
		{
			cout << "The heroes successfully kill the Orcs" << endl;
		}
		else
		{
			chosen_hero = user4;
			cout << hero4 + " gets stabbed by the Orc and Dies" << endl;
			decinc = 0;
			health = 70;
			characterAttributes(chosen_hero, 0);
			cout << "Your Health Decreased by 70!" << endl;
			cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		}
	}
	else
	{
		chosen_hero = user3;
		cout << hero3 + " trips and injures his hand" << endl;
		decinc = 0;
		health = 30;
		characterAttributes(chosen_hero, 0);
		cout << "Your Health decreased by 30!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
	}
	saveFile(user1, user2, user3, user4);
	system("pause");
}

void storyStage6(int* user1, int* user2, int* user3, int* user4)
{
	chosen_hero = NULL;
	openFile();
	user1 = arr1;
	user2 = arr2;
	user3 = arr3;
	user4 = arr4;
	saving_unit++;
	string stage6 = "After their gruesome trek through the Hell bridge, the Heroes seem to find themselves in a place devoid of fear and blood. They find a tavern not too far from the bridge.\nThe Heroes enter this so that they could rest and recover their powers. Inside the tavern, they find a fully functional T.V and a fridge.";
	cout << "\t\t\t\t\t\tLevel 6: Rest Point" << endl << endl;

	for (int i = 0; i < stage6.length(); i++)
	{
		cout << stage6[i];
		Sleep(30);
	}
	cout << endl;

	cout << hero1 + " Strength:        Strike: " << user1[0] << "   " << "Counter: " << user1[1] << "   " << "Intelligence: " << user1[2] << "   " << "Health: " << user1[3] << endl;
	cout << hero2 + " Strength:        Strike: " << user2[0] << "   " << "Counter: " << user2[1] << "   " << "Intelligence: " << user2[2] << "   " << "Health: " << user2[3] << endl;
	cout << hero3 + " Strength:        Strike: " << user3[0] << "   " << "Counter: " << user3[1] << "   " << "Intelligence: " << user3[2] << "   " << "Health: " << user3[3] << endl;
	cout << hero4 + " Strength:        Strike: " << user4[0] << "   " << "Counter: " << user4[1] << "   " << "Intelligence: " << user4[2] << "   " << "Health: " << user4[3] << endl << endl;

	cout << "1. Drink Beer\n2. Sleep for a day\n";
	cout << "Option: ";
	char ch = _getch();

	if (ch == '1')
	{

		chosen_hero = user1;
		decinc = 1;
		health = 20;
		characterAttributes(chosen_hero, 0);
		cout << "Your Health increased by 20!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		chosen_hero = user2;
		characterAttributes(chosen_hero, 0);
		cout << endl << endl << endl;
		cout << "Your Health increased by 20!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		chosen_hero = user3;
		characterAttributes(chosen_hero, 0);
		cout << endl << endl << endl;
		cout << "Your Health increased by 20!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		chosen_hero = user4;
		characterAttributes(chosen_hero, 0);
		cout << endl << endl << endl;
		cout << "Your Health increased by 20!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;



	}
	else
	{
		chosen_hero = user1;
		decinc = 1;
		health = 50;
		characterAttributes(chosen_hero, 0);
		cout << "Your Health increased by 50!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		chosen_hero = user2;
		characterAttributes(chosen_hero, 0);
		cout << endl << endl << endl;
		cout << "Your Health increased by 50!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		chosen_hero = user4;
		characterAttributes(chosen_hero, 0);
		cout << endl << endl << endl;
		cout << "Your Health increased by 50!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
		chosen_hero = user4;
		characterAttributes(chosen_hero, 0);
		cout << endl << endl << endl;
		cout << "Your Health increased by 50!" << endl;
		cout << "Strike: " << chosen_hero[0] << "   " << "Counter: " << chosen_hero[1] << "   " << "Intelligence: " << chosen_hero[2] << "   " << "Health: " << chosen_hero[3] << endl;
	}
	chosen_hero = NULL;
	system("pause");
}

void storyStage7(int* user1, int* user2, int* user3, int* user4)
{
	int random_option = randFunction2();
	chosen_hero = NULL;
	openFile();
	user1 = arr1;
	user2 = arr2;
	user3 = arr3;
	user4 = arr4;
	saving_unit++;
	string stage7 = "After walking for days the Heroes seem to approach a Giant gate. The entire gate was pitch black and skulls of unhuman beings were crowning the gate.\nThe Heroes had reached the gates of General Frazz Urb-Luu, an underling of the Demon Demogorgon. The Heroes with their mighty will marched forward\ntowards the gate. But before they could reach the gate they encountered 5 Giant orcs and 5 regular orcs.\nThe Heroes were once against faced with a battle";
	cout << "\t\t\t\t\t\tLevel 7: Gate of Fraaz Urb-Luu" << endl << endl;

	for (int i = 0; i < stage7.length(); i++)
	{
		cout << stage7[i];
		Sleep(30);
	}
	cout << endl;
	cout << "1. All Heroes use special attribute.\n2. Attack the orcs one by one." << endl;
	cout << "Option";
	char ch = _getch();
	cout << endl;
	if (ch == 1)
	{
		if (random_option == 1)
		{
			cout << "The Heroes were killed in an epic battle. They could not succeed." << endl;
			system("pause");
			cout << "\t\t\t\t\t\t\t\tGAME OVER" << endl << endl;
			system("cls");
			system("pause");
		}
		else
		{
			cout << "The Hereos killed the Giant Orcs and enter the forged castle to fight the General" << endl;
			system("pause");
			cout << "To be Continued" << endl;
			system("pause");
			system("cls");

		}
	}
	else
	{
		cout << "The Heroes were killed in an epic battle. They could not succeed." << endl;
		system("pause");
		cout << "\t\t\t\t\t\t\t\tGAME OVER" << endl << endl;
		system("pause");
		system("cls");
	}

}



void characterAttributes(int* user1, int temp)
{
	int strike_size = user1[0];
	int health_size = user1[3];
	if (temp == 0)
	{
		if (health > 0 && decinc == 0)
		{
			int new_health = health_size - health;
			user1[3] = new_health;
		}
		else if (health > 0 && decinc == 1)
		{
			int new_health = health_size + health;
			user1[3] = new_health;
		}

		if (strike > 0 && decinc == 1)
		{
			int new_strike = strike_size + strike;
			user1[0] = new_strike;
		}
	}

	else if (temp == 1)   //temporary change;
	{
		user1[3] = health_size;
		user1[0] = strike_size;
	}
}

void charactersArray(int arr1[3], int arr2[3], int arr3[3], int arr4[3], int arr5[3], int arr6[3], int arr7[3], int arr8[3])
{
	cout << setw(75) << "CAUTION: YOU CAN ONLY CHOOSE EACH HERO ONCE!" << endl << endl << endl;
	cout << setw(60) << "CHOOSE 4 HEROES " << endl << endl;
	cout << setw(68) << "Note: Enter a digit from 1 to 8." << endl << endl;

	cout << setw(63) << "Choose your first hero: ";

	cin >> user_1;
	cout << setw(66);
	if (user_1 == 1)
	{
		cout << "You have chosen Human Fighter" << endl;
		user1 = human_fighter;
		hero1 = "Human Fighter";
	}
	else if (user_1 == 2)
	{
		cout << "You have chosen Half-Elf Fighter" << endl;
		user1 = halfelf_fighter;
		hero1 = "Half-Elf Fighter";
	}
	else if (user_1 == 3)
	{
		cout << "You have chosen Wood-Elf Fighter" << endl;
		user1 = woodelf_fighter;
		hero1 = "Wood-Elf Fighter";
	}
	else if (user_1 == 4)
	{
		cout << "You have chosen Halfing Rogue" << endl;
		user1 = halfing_rogue;
		hero1 = "Halfing Rogue";
	}
	else if (user_1 == 5)
	{
		cout << "You have chosen Human Druid" << endl;
		user1 = human_druid;
		hero1 = "Human Druid";
	}
	else if (user_1 == 6)
	{
		cout << "You have chosen Half-Elf Wizard" << endl;
		user1 = halfelf_wizard;
		hero1 = "Half-Elf Wizard";
	}
	else if (user_1 == 7)
	{
		cout << "You have chosen Dwarf Cleric" << endl;
		user1 = dwarf_cleric;
		hero1 = "Dwarf Cleric";
	}
	else if (user_1 == 8)
	{
		cout << "You have chosen Human Cleric" << endl;
		user1 = human_cleric;
		hero1 = "Human Cleric";
	}

	cout << setw(64) << "Choose your second hero: ";

	cin >> user_2;
	cout << setw(66);
	if (user_2 == 1)
	{
		cout << "You have chosen Human Fighter" << endl;
		user2 = human_fighter;
		hero2 = "Human Fighter";
	}
	else if (user_2 == 2)
	{
		cout << "You have chosen Half-Elf Fighter" << endl;
		user2 = halfelf_fighter;
		hero2 = "Half-Elf Fighter";
	}
	else if (user_2 == 3)
	{
		cout << "You have chosen Wood-Elf Ranger" << endl;
		user2 = woodelf_fighter;
		hero2 = "Wood-Elf Fighter";
	}
	else if (user_2 == 4)
	{
		cout << "You have chosen Halfing Roque" << endl;
		user2 = halfing_rogue;
		hero2 = "Halfing Rogue";
	}
	else if (user_2 == 5)
	{
		cout << "You have chosen Human Druid" << endl;
		user2 = human_druid;
		hero2 = "Human Druid";
	}
	else if (user_2 == 6)
	{
		cout << "You have chosen Half-Elf Wizard" << endl;
		user2 = halfelf_wizard;
		hero2 = "Half-Elf Wizards";
	}
	else if (user_2 == 7)
	{
		cout << "You have chosen Dward Cleric" << endl;
		user2 = dwarf_cleric;
		hero2 = "Dwarf Cleric";
	}
	else if (user_2 == 8)
	{
		cout << "You have chosen Human Cleric" << endl;
		user2 = human_cleric;
		hero2 = "Human Cleric";
	}

	cout << setw(63) << "Choose your third hero: ";

	cin >> user_3;
	cout << setw(66);
	if (user_3 == 1)
	{
		cout << "You have chosen Human Fighter" << endl;
		user3 = human_fighter;
		hero3 = "Human Fighter";
	}
	else if (user_3 == 2)
	{
		cout << "You have chosen Half-Elf Fighter" << endl;
		user3 = halfelf_fighter;
		hero3 = "Half-Elf Fighter";
	}
	else if (user_3 == 3)
	{
		cout << "You have chosen Wood-Elf Ranger" << endl;
		user3 = woodelf_fighter;
		hero3 = "Wood-Elf Ranger";
	}
	else if (user_3 == 4)
	{
		cout << "You have chosen Halfing Roque" << endl;
		user3 = halfing_rogue;
		hero3 = "Halfing Rogue";
	}
	else if (user_3 == 5)
	{
		cout << "You have chosen Human Druid" << endl;
		user3 = human_druid;
		hero3 = "Human Druid";
	}
	else if (user_3 == 6)
	{
		cout << "You have chosen Half-Elf Wizard" << endl;
		user3 = halfelf_wizard;
		hero3 = "Half-Elf Wizard";
	}
	else if (user_3 == 7)
	{
		cout << "You have chosen Dwarf Cleric" << endl;
		user3 = dwarf_cleric;
		hero3 = "Dwarf Cleric";
	}
	else if (user_3 == 8)
	{
		cout << "You have chosen Human Cleric" << endl;
		user3 = human_cleric;
		hero3 = "Human Cleric";
	}

	cout << setw(63) << "Choose your final hero: ";

	cin >> user_4;
	cout << setw(66);
	if (user_4 == 1)
	{
		cout << "You have chosen Human Fighter" << endl;
		user4 = human_fighter;
		hero4 = "Human Fighter";
	}
	else if (user_4 == 2)
	{
		cout << "You have chosen Half-Elf Fighter" << endl;
		user4 = halfelf_fighter;
		hero4 = "Half-Elf Fighter";
	}
	else if (user_4 == 3)
	{
		cout << "You have chosen Wood-Elf Ranger" << endl;
		user4 = woodelf_fighter;
		hero4 = "Wood-Elf Ranger";
	}
	else if (user_4 == 4)
	{
		cout << "You have chosen Halfing Rogue" << endl;
		user4 = halfing_rogue;
		hero4 = "Halfing Rogue";
	}
	else if (user_4 == 5)
	{
		cout << "You have chosen Human Druid" << endl;
		user4 = human_druid;
		hero4 = "Human Druid";
	}
	else if (user_4 == 6)
	{
		cout << "You have chosen Half-Elf Wizard" << endl;
		user4 = halfelf_wizard;
		hero4 = "Half-Elf Wizard";
	}
	else if (user_4 == 7)
	{
		cout << "You have chosen Dwarf Cleric" << endl;
		user4 = dwarf_cleric;
		hero4 = "Dwarf Cleric";
	}
	else if (user_4 == 8)
	{
		cout << "You have chosen Human Cleric" << endl;
		user4 = human_cleric;
		hero4 = "Human Cleric";
	}

}

void new_game()
{
	string name = "The story so far. The demon's layer erupted through the abyss onto the Earth's Surface."
		" Weeping of monks incapsulated the entire village.\n"
		"King Bruenor sends his friend Drizzt DoUrden to find out what is happening beneath the surface\n"
		"but it becomes all too clear when the demon lord Demogorgon ravages the drow city of Menzobarranzan and\n"
		"has made it his stronghold. Demogorgon is trying bring more demons into this world."
		" In the madness of the dark, who will be the light to shine\nagainst the demons."
		" Four heroes are chosen by God blessed with magical abilities and prowess to destroy these demons and bring peace to the entire world.\n\n\n"
		"Demogorgon is hiding in an old Church castle with his minions. He has gained sufficient power and is trying to summon his fellow demons into this world.\nIf he succeeds the world will be destroyed. It is the job of you Heroes to defeat Demogorgon\nand save the world. Go forth and do what is necessary to save humanity. Godspeed!";




	for (int i = 0; i < name.length(); i++)
	{
		cout << name[i];
		Sleep(30);
	}
}


void menu()    // Menu Page
{
	//WORD color = 0x0F;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

	int input_main_menu;
	cout << endl << endl << endl;
	cout << "\t\t                  /\\           /\\        --------   -----     ---   ---      ---     " << endl;
	cout << "\t\t                 /  \\         /  \\       |  ____|   | |\\ \\    | |   | |      | |       " << endl;
	cout << "\t\t                / /\\ \\       / /\\ \\      |  |___    | | \\ \\   | |   | |      | |          " << endl;
	cout << "\t\t               / /  \\ \\     / /  \\ \\     |   ___|   | |  \\ \\  | |   | |      | |         " << endl;
	cout << "\t\t              / /    \\ \\   / /    \\ \\    |  |       | |   \\ \\ | |   | |      | |           " << endl;
	cout << "\t\t             / /      \\ \\ / /      \\ \\   |  |___    | |    \\ \\| |    \\ \\_____/ /            " << endl;
	cout << "\t\t            /_/        \\___/        \\_\\  |______|   |_|     \\___|     \\_______/         " << endl;
	cout << endl << endl;

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	system("pause");
	system("cls");
	cout << endl << endl;

	cout << setw(65) << "Press 1 to Start New Game" << endl;
	cout << endl;
	cout << setw(65) << "Press 2 to Continue Game" << endl;
	cout << endl;
	cout << setw(60) << "Press 3 to Exit" << endl;
	char ch = _getch();

	if (ch == '1')
	{
		system("cls");
		new_game();
		cout << endl << endl;
		system("pause");
		system("cls");
		charactersName();
		system("pause");
		cout << endl << endl;
		charactersArray(human_fighter, halfelf_fighter, woodelf_fighter, halfing_rogue, human_druid, halfelf_wizard, dwarf_cleric, human_cleric);
		system("cls");
		storyStage1(user1, user2, user3, user4);
		system("cls");
		storyStage2(user1, user2, user3, user4);
		system("cls");
		storyStage3(user1, user2, user3, user4);
		system("cls");
		storyStage4(user1, user2, user3, user4);
		system("cls");
		storyStage5(user1, user2, user3, user4);
		system("cls");
		storyStage6(user1, user2, user3, user4);
		system("cls");
		storyStage7(user1, user2, user3, user4);
		system("cls");
	}
	else if (ch == '2')
	{
		openFile();
		if (saving_unit == 1)
		{
			system("cls");
			storyStage2(user1, user2, user3, user4);
			system("cls");
			storyStage3(user1, user2, user3, user4);
			system("cls");
			storyStage4(user1, user2, user3, user4);
			system("cls");
			storyStage5(user1, user2, user3, user4);
			system("cls");
			storyStage6(user1, user2, user3, user4);
			system("cls");
			storyStage7(user1, user2, user3, user4);
			system("cls");
		}
		else if (saving_unit == 2)
		{
			system("cls");
			storyStage3(user1, user2, user3, user4);
			system("cls");
			storyStage4(user1, user2, user3, user4);
			system("cls");
			storyStage5(user1, user2, user3, user4);
			system("cls");
			storyStage6(user1, user2, user3, user4);
			system("cls");
			storyStage7(user1, user2, user3, user4);
			system("cls");
		}
		else if (saving_unit == 3)
		{
			system("cls");
			storyStage4(user1, user2, user3, user4);
			system("cls");
			storyStage5(user1, user2, user3, user4);
			system("cls");
			storyStage6(user1, user2, user3, user4);
			system("cls");
			storyStage7(user1, user2, user3, user4);
			system("cls");
		}
		else if (saving_unit == 4)
		{
			system("cls");
			storyStage5(user1, user2, user3, user4);
			system("cls");
			storyStage6(user1, user2, user3, user4);
			system("cls");
			storyStage7(user1, user2, user3, user4);
			system("cls");
		}
		else if (saving_unit == 5)
		{
			system("cls");
			storyStage6(user1, user2, user3, user4);
			system("cls");
			storyStage7(user1, user2, user3, user4);
			system("cls");
		}
		else if (saving_unit == 6)
		{
			system("cls");
			storyStage7(user1, user2, user3, user4);
			system("cls");
		}
	}
	else if (ch == '3')
	{
		return;
	}
}

int main()
{
	PlaySound(TEXT("dnd.wav"), NULL, SND_ASYNC);
	system("color 0F");
	Sleep(1800);
	menu();
	system("pause");
}