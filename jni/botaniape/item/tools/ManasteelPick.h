#pragma once
#include "PickaxeItem.h"
//how does this work for you Joe? Maybe I should add something totally idiotic to my class
// :P

class ManasteelPick : public PickaxeItem {
public:
	virtual float getDestroySpeed(ItemInstance*, Tile*);
	virtual int getAttackDamage(Entity*);
	//using mineBlock makes me crash. I need to know how to use it.
	ManasteelPick(int);
};
