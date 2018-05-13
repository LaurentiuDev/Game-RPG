#pragma once
#ifndef STORE_H
#define STORE_H
#include "Player.h"
#include "Armor.h"
#include "Weapon.h"
class Store
{
public:
	void enter(Player& player);

private:
	Armor mArmorItem;
	Weapon mWeapon;
};




#endif

