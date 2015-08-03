#pragma once

#include "FlowerTile.h"

class Puredaisy : public FlowerTile {
public:
	virtual void animateTick(TileSource*, int, int, int, Random*);
	virtual int getResource(int, Random*);
	virtual int getResourceCount(Random*);
	
	Puredaisy(int, std::string const&, Material const*);
};
