#include "Store.h"
#include "Random.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void Store::enter(Player& player)
{
	
	std::vector<Armor> armor ;

	mArmorItem.mName = "Shield";
	mArmorItem.mArmorValue = 5;
	mArmorItem.mCost = 400;
	armor.push_back(mArmorItem);

	mArmorItem.mName = "Boots";
	mArmorItem.mArmorValue = 3;
	mArmorItem.mCost = 250;
	armor.push_back(mArmorItem);

	mArmorItem.mName = "Armor";
	mArmorItem.mArmorValue = 10;
	mArmorItem.mCost = 900;
	armor.push_back(mArmorItem);

	mArmorItem.mName = "Shield";
	mArmorItem.mArmorValue = 4;
	mArmorItem.mCost = 380;
	armor.push_back(mArmorItem);

	mArmorItem.mName = "Hat";
	mArmorItem.mArmorValue = 2;
	mArmorItem.mCost = 200;
	armor.push_back(mArmorItem);

	mArmorItem.mName = "Shield";
	mArmorItem.mArmorValue = 6;
	mArmorItem.mCost = 500;
	armor.push_back(mArmorItem);

	mArmorItem.mName = "Armor";
	mArmorItem.mArmorValue = 15;
	mArmorItem.mCost = 1500;
	armor.push_back(mArmorItem);


	vector<Weapon> weapon;
	mWeapon.mName = "Long Sword";
	mWeapon.mDamageRange.mLow = 3;
	mWeapon.mDamageRange.mHigh = 10;
	mWeapon.mMagicPoints = 0;
	mWeapon.mCost = 200;
	weapon.push_back(mWeapon);

	mWeapon.mName = "Staff";
	mWeapon.mDamageRange.mLow = 4;
	mWeapon.mDamageRange.mHigh = 11;
	mWeapon.mMagicPoints = 10;
	mWeapon.mCost = 500;
	weapon.push_back(mWeapon);

	mWeapon.mName = "Scepters";
	mWeapon.mDamageRange.mLow = 8;
	mWeapon.mDamageRange.mHigh = 15;
	mWeapon.mMagicPoints = 10;
	mWeapon.mCost = 1500;
	weapon.push_back(mWeapon);

	mWeapon.mName = "Great Axe";
	mWeapon.mDamageRange.mLow = 15;
	mWeapon.mDamageRange.mHigh = 30;
	mWeapon.mMagicPoints = 0;
	mWeapon.mCost = 2500;
	weapon.push_back(mWeapon);

	
	unsigned int i,j;
	cout << "============================================" << endl;
	cout << "Welcom to  Store!" << endl;
	cout << "You have " << player.getGold() << " gold!" << endl;
	
	cout << "-----------Armors------------------" << endl;
	for (i = 0; i < armor.size(); i++)
	{	
		cout << i << ") " << armor[i].mName<<" - "<<armor[i].mArmorValue<< " defense --> " << armor[i].mCost << " gold" << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "--------------Weapons-----------------" << endl;
	for (j = 0; j < weapon.size(); j++)
	{
		cout << j << ") " << weapon[j].mName << "      --> damage : " << weapon[j].mDamageRange.mLow<<"-"<<weapon[j].mDamageRange.mHigh << "--> Magic Ponts : " << weapon[j].mMagicPoints<<"    --> "<<armor[j].mCost << " gold" << endl;
	}
	cout << "============================================" << endl;

	int chose;
	int NumberArmor;
	cin >> chose;
	cout << "You chose items : 1) Armors ,  or  2) Weapons" << endl;
	if (chose == 1)
	{
		cout << "You chose a armor :";
		cin >> NumberArmor;
		player.changeArmor(armor[NumberArmor].mName, armor[NumberArmor].mArmorValue);
		
	}
}