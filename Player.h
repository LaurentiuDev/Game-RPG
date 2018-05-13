#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include "Spell.h"
#include "Armor.h"
#include <string>

class Player
{
public:
	Player();

	bool isDead();

	std::string getName();
	int			getArmor();
	void		setArmor(int value);
	void		changeWeapon(std::string name,int lowDamage,int highDamage,int magicPoints);
	void		changeArmor(std::string name, int defense);
	void takeDamage(int damage);

	void createClass();
	bool attack(Monster& monster);
	void levelUp(std::string& namePlayer);
	void rest();
	void viewStats();
	void victory(int xp);
	void gameover();
	void displayHitPoints();
	void goldAmountReward(int gold);
	void randomGoldAmountReward(std::string nameMonster);
	int getGold();
private:
	std::string mName;
	std::string mClassName;
	
	int mAccuracy;
	int mHitPoints;
	int mMaxHitPoints;
	int mMagicPoints;
	int mMaxMagicPoints;
	int mExpPoints;
	int mNextLevelExp;
	int mLevel;
	int mArmor;
	int mgoldAmount;
	Weapon mWeapon;
	Armor mArmorItem;
	Spell mSpell;
};

#endif