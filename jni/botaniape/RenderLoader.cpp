#include "RenderLoader.h"

#include "minecraftpe/tile/Tile.h"

using namespace std;

map<int, Renderer*> RenderLoader::renderMap;

void RenderLoader::loadRender(int id, Renderer* renderer) {
	renderMap[id] = renderer;
}

bool RenderLoader::load(int id, const TilePos& tilepos, Tile* tile, TileTessellator* tessellator) {
	if(renderMap.find(id) != renderMap.end()) {
		renderMap[id]->render(tilepos, (Tile*)tile, tessellator);
		return true;
	}
	return false;
}
