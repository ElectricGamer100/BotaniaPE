#pragma once
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/item/TileItem.h"

class PetalApothecary : public Tile {
public:
	static PetalApothecary* petalApothecary;
	PetalApothecary(int, Material const*);
};
