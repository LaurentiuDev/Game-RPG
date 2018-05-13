#include "Map.h"
#include "Random.h"
#include "Player.h"
#include "Store.h"
#include <cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

int main()
{
	srand(time(0));

	Map gameMap;
	Player mainPlayer;
	mainPlayer.createClass();

	bool done = false;
	while (!done)
	{
		gameMap.printPlayerPos();
		int selection = 1;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cin >> selection;
		Monster* monster = 0;
		switch (selection)
		{
		case 1:
			gameMap.movePlayer();
			if (gameMap.getPlayerXPos() == 2 && gameMap.getPlayerYPos() == 3)
			{
				Store store;
				store.enter(mainPlayer);
				break;
			}
			monster = gameMap.checkRandomEncounter();
			if (monster != 0)
			{
				int armor = mainPlayer.getArmor();
				while (true)
				{
					mainPlayer.displayHitPoints();
					monster->displayHitPoints();
					
					cout << endl;
					bool runAway = mainPlayer.attack(*monster);
					if (runAway)
						break;
					
					if (monster->isDead())
					{
						mainPlayer.setArmor(armor);
						mainPlayer.randomGoldAmountReward(monster->getName());
						mainPlayer.victory(monster->getXPReward());
						mainPlayer.levelUp(mainPlayer.getName());
						
						break;
					}
					monster->attack(mainPlayer);
					
					if (mainPlayer.isDead())
					{
						mainPlayer.gameover();
						done = true;
						break;
					}
				}

				delete monster;
				monster = 0;
			}
			break;
		case 2:
			{
			int randomEncounterDuringRest = Random(1, 4);
			if (randomEncounterDuringRest == 1) {
				mainPlayer.rest();
			}
			else {

				do {
					monster = gameMap.checkRandomEncounter();
				} while (monster == 0);

					int armor = mainPlayer.getArmor();
					while (true)
					{
						mainPlayer.displayHitPoints();
						monster->displayHitPoints();

						cout << endl;
						bool runAway = mainPlayer.attack(*monster);
						if (runAway)
							break;

						if (monster->isDead())
						{
							mainPlayer.setArmor(armor);
							mainPlayer.randomGoldAmountReward(monster->getName());
							mainPlayer.victory(monster->getXPReward());
							mainPlayer.levelUp(mainPlayer.getName());

							break;
						}
						monster->attack(mainPlayer);

						if (mainPlayer.isDead())
						{
							mainPlayer.gameover();
							done = true;
							break;
						}
					} //end while
				
			} //end else
			delete monster;
			monster = 0;
			} //end block
			break;
		case 3:
			mainPlayer.viewStats();
			break;
		case 4:
			done = true;
			break;
		}
	}
	system("pause");
	return 0;
}