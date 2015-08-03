#include "ManasteelPick.h"

ManasteelPick::ManasteelPick(int id) : PickaxeItem(id) {
	setNameID("manasteelPick");
	setIcon("manasteelPick",0);
	
	maxDamage = 1500;
}

float ManasteelPick::getDestroySpeed(ItemInstance* inst, Tile* tile){
	//wtf, everytime I try, I fail.
	return 0.0;
}

int ManasteelPick::getAttackDamage(Entity* entity){
	return 2; //but is it worthy?
}
