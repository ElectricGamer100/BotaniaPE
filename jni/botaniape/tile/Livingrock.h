#pragma once

#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/item/TileItem.h"

class Livingrock : public Tile {
public:
	static Livingrock* livingrock;
	
	Livingrock(int, std::string const&, Material const*);
};
