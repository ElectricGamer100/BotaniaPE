#pragma once

#include "Renderer.h"

#include "minecraftpe/client/renderer/TileTessellator.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/level/TileSource.h"
#include "minecraftpe/util/TilePos.h"

#include <map>

using namespace std;

class RenderLoader {
public:
	static map<int, Renderer*> renderMap;
	static void loadRender(int, Renderer*);
	static bool load(int, const TilePos&, Tile*, TileTessellator*);
};
