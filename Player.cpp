#include "Player.h"
#include "Random.h"
#include "Armor.h"
#include "Spell.h"
#include<string>
#include<iostream>

using namespace std;

Player::Player()
{
	mName = "Default";
	mClassName = "Default";
	mAccuracy = 0;
    mHitPoints=0;
	mMaxHitPoints=0;
	mMagicPoints = 0;
	mMaxMagicPoints = 0;
	mExpPoints=0;
	mNextLevelExp=0;
	mgoldAmount = 0;
    mLevel=0;
	mArmor=0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mDamageRange.mLow = 0;
	mWeapon.mDamageRange.mHigh = 0;
	mWeapon.mMagicPoints = 0;
	mSpell.mName = "Default Spell Name";
	mSpell.mDamageRange.mLow = 0;
	mSpell.mDamageRange.mHigh = 0;
	mSpell.mMagicPointsRequired = 0;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

void Player::setArmor(int value)
{
	mArmor = value;
}

void Player::changeWeapon(std::string name, int lowDamage, int highDamage, int magicPoints)
{
	mWeapon.mName = name;
	mWeapon.mDamageRange.mLow = lowDamage;
	mWeapon.mDamageRange.mHigh = highDamage;
	mWeapon.mMagicPoints = magicPoints;
}

void Player::changeArmor(std::string name, int defense)
{
	mArmorItem.mName = name;
	mArmorItem.mArmorValue = defense;
}
void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	cout << "CARACTER CLASS GENERATION" << endl;
	cout << "=========================" << endl;

	cout << "Enter your caracter's name: ";
	getline(cin, mName);

	cout << "Please select a caracter class number..." << endl;
	cout << "1)Fighter  2)Wizard  3)Cleric  4)Thief  5)Elf  6)Dwarf  :";
	int characterNum = 1;
	cin >> characterNum;

	switch (characterNum)
	{
	case 1:
		mClassName = "Fighter";
		mAccuracy = 10;
		mHitPoints = 20;
		mMaxHitPoints = 20;
		mMagicPoints = 10;
		mMaxMagicPoints = 10;
		mgoldAmount = 0;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 4;
		mWeapon.mName = "Long Sword";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 8;
		mWeapon.mMagicPoints = 0;
		mArmorItem.mName = "";
		mArmorItem.mArmorValue = 0;
		mSpell.mName = "Shield";
		mSpell.mMagicPointsRequired = 2;
		mSpell.mDamageRange.mLow = 1;
		mSpell.mDamageRange.mHigh = 5;
		break;
	case 2:
		mClassName = "Wizard";
		mAccuracy = 5;
		mHitPoints = 10;
		mMaxHitPoints = 10;
		mMagicPoints = 20;
		mMaxMagicPoints = 20;
		mgoldAmount = 0;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 1;
		mWeapon.mName = "Staff";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 4;
		mWeapon.mMagicPoints = 0;
		mSpell.mName = "Fire ball";
		mSpell.mMagicPointsRequired = 4;
		mSpell.mDamageRange.mLow = 4;
		mSpell.mDamageRange.mHigh = 12;

		break;
	case 3:
		mClassName = "Cleric";
		mAccuracy = 8;
		mHitPoints = 15;
		mMaxHitPoints = 15;
		mMagicPoints = 10;
		mMaxMagicPoints = 10;
		mgoldAmount = 0;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 3;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		mWeapon.mMagicPoints = 0;
		mSpell.mName = "Shield";
		mSpell.mMagicPointsRequired = 2;
		mSpell.mDamageRange.mLow = 1;
		mSpell.mDamageRange.mHigh = 5;
		break;
	case 5:
		mClassName = "Elf";
		mAccuracy = 8;
		mHitPoints = 15;
		mMaxHitPoints = 15;
		mMagicPoints = 10;
		mMaxMagicPoints = 10;
		mgoldAmount = 0;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 3;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		mWeapon.mMagicPoints = 0;
		mSpell.mName = "Shield";
		mSpell.mMagicPointsRequired = 2;
		mSpell.mDamageRange.mLow = 1;
		mSpell.mDamageRange.mHigh = 5;
		break;
	case 6:
		mClassName = "Dwarf";
		mAccuracy = 5;
		mHitPoints = 20;
		mMaxHitPoints = 15;
		mMagicPoints = 10;
		mMaxMagicPoints = 10;
		mgoldAmount = 0;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 3;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		mWeapon.mMagicPoints = 0;
		mSpell.mName = "Shield";
		mSpell.mMagicPointsRequired = 2;
		mSpell.mDamageRange.mLow = 1;
		mSpell.mDamageRange.mHigh = 5;

		break;

	default:
		mClassName = "Thief";
		mAccuracy = 7;
		mHitPoints = 12;
		mMaxHitPoints = 12;
		mMagicPoints = 10;
		mMaxMagicPoints = 10;
		mgoldAmount = 0;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mLevel = 1;
		mArmor = 2;
		mWeapon.mName = "Short Sword";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		mWeapon.mMagicPoints = 0;
		mSpell.mName = "Shield";
		mSpell.mMagicPointsRequired = 2;
		mSpell.mDamageRange.mLow = 1;
		mSpell.mDamageRange.mHigh = 5;

		break;
	}


}

bool Player::attack(Monster& monster)
{
	int selection = 1;
	cout << "1) Attack,  2) Run,  3)Cast Spell : ";
	cin >> selection;
	cout << endl;
	
	switch (selection)
	{
	case 1:
		cout << "You attack an " << monster.getName() << " with a " << mWeapon.mName << endl;
		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon.mDamageRange);
			int totalDamage = damage - monster.getArmor();

			if (totalDamage <= 0)
			{
				cout << "Your attack failed to penetrate the armor." << endl;
			}
			else
			{
				cout << "You attack for " << totalDamage << " damage!" << endl;
				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;
	case 2:
		 
		{int roll = Random(1, 4);
		if (roll == 1)
		{
			cout << "You run away!" << endl;
			return true;
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
		}
	
	case 3:
		if (!mName.compare("Wizard"))
		{
			mMagicPoints -= mSpell.mMagicPointsRequired;
			if (mMagicPoints > 0)
			{
				cout << "You attack an " << monster.getName() << " with a " << mSpell.mName << endl;
				
				if (Random(0, 20) < mAccuracy)
				{
					int damage = Random(mSpell.mDamageRange);
					int totalDamage = damage - monster.getArmor();

					if (totalDamage <= 0)
					{
						cout << "Your attack failed to penetrate the armor." << endl;
					}
					else
					{
						cout << "You attack for " << totalDamage << " damage!" << endl;
						monster.takeDamage(totalDamage);
					}
				}
				else
				{
					cout << "You miss!" << endl;
				}
				cout << endl;
			}
		}
		
		else
		{
			mMagicPoints -= mSpell.mMagicPointsRequired;
			if (mMagicPoints > 0)
			{
				int Shield = Random(mSpell.mDamageRange);
				mArmor += Shield;
				cout << "Your armor increased with " << Shield << " points!" << endl;
				cout << "Armor = " << mArmor << endl;
				cout << endl;
			}
		}
		
		break;
	}
	return false;
}

void Player::levelUp(std::string& namePlayer)
{
	if (mExpPoints >= mNextLevelExp)
	{
		cout << "You gained a level!" << endl;
		mLevel++;
		mNextLevelExp = mLevel*mLevel * 1000;
		if (!namePlayer.compare("Figher")) {
			mAccuracy += Random(1, 3);
			mMaxHitPoints += Random(4, 10);
			mMaxMagicPoints += Random(1, 3);
			mArmor += Random(1, 2);
			mHitPoints = mMaxHitPoints;
			mMagicPoints = mMaxMagicPoints;
		}
		else if (!namePlayer.compare("Wizard"))
		{
			mAccuracy += Random(1, 3);
			mMaxHitPoints += Random(2, 6);
			mMaxMagicPoints += Random(5, 10);
			mArmor += Random(1, 2);
			mHitPoints = mMaxHitPoints;
			mMagicPoints = mMaxMagicPoints;

		}
		mAccuracy += Random(1, 3);
		mMaxHitPoints += Random(4, 10);
		mMaxMagicPoints += Random(2, 5);
		mArmor += Random(1, 2);
		mHitPoints = mMaxHitPoints;
		mMagicPoints = mMaxMagicPoints;

		
	}
}

void Player::rest()
{
		cout << "Resting..." << endl;
		mHitPoints = mMaxHitPoints;
		mMagicPoints = mMaxMagicPoints;
}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;
	cout << "Name            = " << mName << endl;
	cout << "Class           = " << mClassName << endl;
	cout << "Accuracy        = " << mAccuracy << endl;
	cout << "HitPoints       = " << mHitPoints << endl;
	cout << "MaxHitPoints    = " << mMaxHitPoints << endl;
	cout << "MagicPoints     = " << mMagicPoints << endl;
	cout << "MaxMagicPoints  = " << mMaxMagicPoints<< endl;
	cout << "XP              = " << mExpPoints << endl;
	cout << "Xp for Next Lvl = " << mNextLevelExp << endl;
	cout << "Level           = " << mLevel << endl;
	cout << "Armor           = " << mArmor << endl;
	cout << "Weapon Name     = " << mWeapon.mName << endl;
	cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow << "-" << mWeapon.mDamageRange.mHigh << endl;
	cout << "Gold            = " << mgoldAmount << endl;
	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp)
{
	cout << "You won the battle!" << endl;
	cout << "You win " << xp << " experience points!"  << endl;
	cout << "You received "<<mgoldAmount<<" gold !"<<endl << endl;
	mExpPoints += xp;
}

std::string Player::getName()
{
	return mName;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "=================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "=================================" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}

void Player::goldAmountReward(int gold)
{
	mgoldAmount += gold;
}

void Player::randomGoldAmountReward( std::string nameMonster)
{
	if (!nameMonster.compare("Orc"))
	{
		int gold = Random(3, 6);
		goldAmountReward(gold);
	}
	else if (!nameMonster.compare("Goblin"))
	{
		int gold = Random(1, 3);
		goldAmountReward(gold);
	}
	else if (!nameMonster.compare("Ogre"))
	{
		int gold = Random(20, 50);
		goldAmountReward(gold);
	}
	else if (!nameMonster.compare("Orc Lord"))
	{
		int gold = Random(50, 200);
		goldAmountReward(gold);
	}
}

int Player::getGold()
{
	return mgoldAmount;
}