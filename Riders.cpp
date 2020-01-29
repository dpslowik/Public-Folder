#include "pch.h"
#include <iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<vector>
#include<map>
#include<set>
#include<random>
#include<ctime>

using namespace std;
deque<char> playerMap;



template<typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin(); element != container.cend(); ++element)
	{
		cout << *element << ' ';
	}
	cout << endl;
}

template<typename T>
void DisplayMap(const T& container)
{
	cout << "S ";
	for (auto element = container.cbegin(); element != container.cend(); ++element)
	{
		cout << *element << ' ';
	}
	cout << "D" << endl;
}


class PlayerTurn
{
public:
	vector<int> experence{ 0 };
	int currentXP = experence[0];

	int turn1 = 0;

	PlayerTurn(int userSelection) : turn1(userSelection)
	{
		
		int turn2 = 7;
		//weapons are placed here to be accessed by everyting
		vector<string> armory{ "Knife", "Crossbow", "Flail", "Broad Sword", "Spell of the Gods", "Dragon Slayer" };
		string inHand1 = armory[0];
		string atPlace = armory[1];

		//assigning random spaces to weapons, monsters and blank
		vector<int> vec1;
		for (int counter = 2; counter < 28; ++counter)
		{
			vec1.push_back(counter);
		}

		srand(time(NULL));
		random_shuffle(vec1.begin(), vec1.end());
		//for weapons
		vector<int> vec2;
		vec2.insert(vec2.begin(), vec1.begin(), vec1.begin() + 5);
		//for monsters
		vector<int> vec3;
		vec3.insert(vec3.begin(), vec1.begin() + 5, vec1.begin() + 19);
		//for blanks
		vector<int> vec4;
		vec4.insert(vec4.begin(), vec1.begin() + 19, vec1.end());

		cout << "\            #*****************************#" << endl;
		cout << "\            *    RIDERS   OF   FORTUNE    *" << endl;
		cout << "\            #*****************************#" << endl;
		
		cout << endl;
		cout << "You are Yarra, a young horseman in search of the illustious" << endl;
		cout << "Chalice of Knowledge, an artifact that will bring you everlasting wisdom. The" << endl;
		cout << "Chalice can only be found in the Dragon's Dungeon after defeating the dragon." << endl;
		cout << "You will need to gain at least 5 Experence Points(XP) to fight the dragon." << endl;
		cout << "You can gain XP by fighting monsters and training." << endl;
		cout << "Search spaces to look for new weapons, fight monsters and train." << endl;
		cout << endl << "Prepare to begin your quest!" << endl;
		cout << endl;
		system("pause");
		system("cls");
		
		do
		{
			vector<char> player1{ '0' };
			//finding the position of the player at the beginning of each turn
			auto value2 = search(playerMap.begin(), playerMap.end(), player1.begin(), player1.end());
			int position1 = distance(playerMap.begin(), value2);
			
			//assigning weapon strength and current weapon
			map<string, int> weapons;
			weapons.insert(make_pair("Knife", 1));
			weapons.insert(make_pair("Crossbow", 3));
			weapons.insert(make_pair("Flail", 4));
			weapons.insert(make_pair("Broad Sword", 5));
			weapons.insert(make_pair("Spell of the Gods", 6));
			weapons.insert(make_pair("Dragon Slayer", 7));
			auto pairFound1 = weapons.find(inHand1);

			cout << "\            #*****************************#" << endl;
			cout << "\            *    RIDERS   OF   FORTUNE    *" << endl;
			cout << "\            #*****************************#" << endl;
			cout << endl;
			cout << "Location on the Map" << endl;
			DisplayMap(playerMap);
			cout << "Stage: " << position1 +1 << endl;
			cout << "Current weapon: " << inHand1 << " +" << pairFound1->second << endl;
			cout << "Current XP: " << experence[0] << endl;

			//assign dragon to end of board
			vector<int> endDragon{ 28 };
			if (find(endDragon.begin(), endDragon.end(), position1) != endDragon.end())
			{
				int dragonXP = 10;
				if (experence[0] >= 5)
				{
					cout << endl;
					cout << "Battle dragon" << endl;
					int dragon1 = 10;
					
					//roll attack dice
					vector<int> sixSided{ 1, 2, 3, 4, 5, 6 };
					random_shuffle(sixSided.begin(), sixSided.end());
					int rollDice3 = sixSided[0];

					cout << "Your attack power: " << rollDice3 + pairFound1->second << endl;
					cout << "Dragon health points: " << dragon1 << endl;
					if ((rollDice3 + pairFound1->second) >= dragon1)
					{
						//cout << "Dragon defeated!" << endl;
						cout << endl;
						cout << "Due to your cunning and experience, you have defeated the deadly dragon." << endl;
						cout << "Your quest has ended good sir. You've obtained the Chalice of Knowledge" << endl;
						cout << "and all of Earth's mysteries are revealed." << endl;
						cout << endl << "The end" << endl;
						break;
					}
					else
					{
						cout << endl;
						cout << "You have been killed." << endl;
						playerMap.clear();
						playerMap.resize(28);
						fill(playerMap.begin(), playerMap.end(), '*');
						playerMap.push_front('0');
					}

				}
				else
				{
					cout << endl;
					cout << "Alas, the dragon's eyes stare at you and places you under his spell. You" << endl;
					cout << "try to move but fail to do so and find yourself torched by the dragon's fire." << endl;
					cout << "If only you had gained more experience, you could have seen it coming..." << endl;
					playerMap.clear();
					playerMap.resize(27);
					fill(playerMap.begin(), playerMap.end(), '*');
					playerMap.push_front('*');
				}
			}

			cout << endl;
			cout << "1: Roll dice, move foward." << endl;
			cout << "2: Explore current positon." << endl;
			cout << "9: End quest." << endl;
			cout << "Enter selection: ";
			cin >> turn1;

			{
				//Uncomment if you don't wan't the player to repeat the same turn
				//if (turn1 == turn2)
				//{
				//	cout << endl;
				//	cout << "You've already done that." << endl << endl;
				//}
				if (turn1 == 1)
				{
					cout << endl;
					cout << "Rolling dice...";

					srand(time(NULL));
					vector<int> sixSided{ 1, 2, 3, 4, 5, 6 };
					random_shuffle(sixSided.begin(), sixSided.end());

					int rollDice = sixSided[0];
					if ((position1 + rollDice) >= 28)
					{
						//ensure player cannot go past end of board
						playerMap.resize(28);
						fill(playerMap.begin(), playerMap.end(), '*');
						playerMap.push_back('0');
						cout << "You have reached the end, prepare to encounter the Dragon!" << endl;


					}
					else
					{
						//moving the player along the map line
						cout << "Player moves " << rollDice << " spaces forward." << endl;
						cout << endl;
						for (int index = 0; index < rollDice; ++index)
						{
							playerMap.pop_back();
							playerMap.push_front('*');
						}
					}

					//find where the player is at after moving
					auto value3 = search(playerMap.begin(), playerMap.end(), player1.begin(), player1.end());
					int position2 = distance(playerMap.begin(), value3);
					if (value3 != playerMap.end())
					{
						//cout << "You are on stage " << position2 + 1 << endl;
					}


				}
				else if (turn1 == 2)
				{
					cout << endl;
					cout << "Dismounting, exploring space..." << endl;
					vector<int> threeChoices{ 1, 2, 3 };
					random_shuffle(threeChoices.begin(), threeChoices.end());
					int randomChoice = threeChoices[0];

					//rolling second dice for attack power
					vector<int> sixSided{ 1, 2, 3, 4, 5, 6 };
					random_shuffle(sixSided.begin(), sixSided.end());
					int rollDice2 = sixSided[0];

					//allocating specific places for monsters, weapons, all else is blank
					vector<int> monsterLocals;
					monsterLocals.insert(monsterLocals.begin(), vec3.begin(), vec3.end());
					vector<int> weaponLocals;
					weaponLocals.insert(weaponLocals.begin(), vec2.begin(), vec2.end());
					
					if (find(monsterLocals.begin(), monsterLocals.end(), position1) != monsterLocals.end())
					{
						cout << "MONSTER!" << endl;
						vector<int> monsterPower{ 3, 4, 5, 6, 7 };
						random_shuffle(monsterPower.begin(), monsterPower.end());
						int monster1 = monsterPower[0];
						cout << "Your attack power: " << rollDice2 + pairFound1->second << endl;
						cout << "Monster health points: " << monster1 << endl;
						if ((rollDice2 + pairFound1->second) >= monster1)
						{
							cout << endl;
							cout << "Monster defeated! You gain 2 XP" << endl;
							cout << endl;
							//experence.insert(experence.begin(), 2);
							for (int adder = 2; adder < 3; ++adder)
							{
								int currentXP = experence[0];
								experence.insert(experence.begin(), (currentXP + adder));
							}
						}
						else
						{
							cout << endl;
							cout << "You have been killed." << endl;
							playerMap.clear();
							playerMap.resize(28);
							fill(playerMap.begin(), playerMap.end(), '*');
							playerMap.push_front('0');
						}

					}
					else if (find(weaponLocals.begin(), weaponLocals.end(), position1) != weaponLocals.end())
					{
						cout << "Weapon found!" << endl;
						if (position1 == weaponLocals[0])
						{
							atPlace = armory[0];
						}
						else if (position1 == weaponLocals[1])
						{
							atPlace = armory[1];
						}
						else if (position1 == weaponLocals[2])
						{
							atPlace = armory[2];
						}
						else if (position1 == weaponLocals[3])
						{
							atPlace = armory[3];
						}
						else if (position1 == weaponLocals[4])
						{
							atPlace = armory[4];
						}
						else if (position1 == weaponLocals[5])
						{
							atPlace = armory[5];
						}

						auto pairFound1 = weapons.find(inHand1);
						auto pairFound2 = weapons.find(atPlace);
						if (pairFound1 != weapons.end())
						{
							cout << pairFound1->first << ": attack + " << pairFound1->second << endl;
							cout << pairFound2->first << ": attack + " << pairFound2->second << endl;
						}

						if (pairFound1->second > pairFound2->second)
						{
							cout << pairFound1->first << " is better, so keep it" << endl;
							cout << endl;
							//cout << inHand1 << endl;
						}
						else
						{
							cout << pairFound2->first << " is better, so pick it up" << endl;
							cout << endl;
							inHand1 = atPlace;
							//cout << inHand1 << endl;
						}
					}
					


					else
					{
						cout << endl;
						cout << "There is nothing for you to do, so you reflect upon your adventure" << endl;
						cout << "thus far.  You take the time to train and enhance your reflexes." << endl;
						cout << "Your XP increases by 1" << endl;
						cout << endl;
						for (int adder = 1; adder < 2; ++adder)
						{
							int currentXP = experence[0];
							experence.insert(experence.begin(), (currentXP + adder));
						}

					}


				}
				else if (turn1 == 9)
				{
					cout << endl;
					cout << "Farewell..." << endl;
					break;
				}

				else
				{
					cout << endl;
					cout << "Invalid selection." << endl;
				}
				turn2 = turn1;
			}
			system("pause");
			system("cls");
		} while (turn1 != 9);

	}

};


int main()
{
	system("cls");
	playerMap.resize(28);
	fill(playerMap.begin(), playerMap.end(), '*');
	playerMap.push_front('0');
	//fill container starting at 2 to 27, only works with <int>
	vector<int> myVec1;
	for (int counter = 2; counter < 28; ++counter)
	{
		myVec1.push_back(counter);
	}
	//calling PlayerTurn and seting value to null(0) to get things started
	//any value will work, but it needs a value to start
	PlayerTurn yourTurn(0);



	return 0;
}

