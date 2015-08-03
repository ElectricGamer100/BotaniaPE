#pragma once
#include "minecraftpe/util/TilePos.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/client/renderer/TileTessellator.h"
#include "minecraftpe/level/TileSource.h"

class Renderer {
public:
	virtual void render(const TilePos&, Tile*, TileTessellator*) = 0;
};
