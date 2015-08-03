#include "PickaxeItem.h"

PickaxeItem* PickaxeItem::manasteelPick = NULL;

PickaxeItem::PickaxeItem(int id) : Item(id) {
	setMaxStackSize(1);
	isHandEquipped();
}
