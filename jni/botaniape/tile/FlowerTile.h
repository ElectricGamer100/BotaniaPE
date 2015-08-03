#pragma once

#include "minecraftpe/item/TileItem.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/level/TileSource.h"

class FlowerTile : public Tile {
public:
	static FlowerTile* puredaisy;
	static FlowerTile* mysticalFlower;
	
	virtual void addAABBs(TileSource *, int, int, int, const AABB *, std::vector<AABB> &);
	virtual bool isPathfindable(TileSource*, int, int, int);
	
	FlowerTile(int, std::string const&, Material const*);
};
