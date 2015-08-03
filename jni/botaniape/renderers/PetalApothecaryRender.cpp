#include "PetalApothecaryRender.h"
//I think ModPE should be jealous now.

void PetalApothecaryRender::render(const TilePos& pos, Tile* tile, TileTessellator* tess) {
	tess->renderTexture = true;
	int x = pos.x, y = pos.y, z = pos.z;
	
	tess->texture = Tile::tiles[4]->getTexture(0,0); //why u so difficult?
	
	tess->aabb = AABB(0.0, 0.0, 0.0, 1.0, 0.125, 1.0);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.0625, 0.125, 0.0625, 0.9375, 0.1875, 0.9375);
	tess->tessellateBlockInWorld(tile, {x, y, z}); //do I need to put this each time? Its annoying.
	tess->aabb = AABB(0.125, 0.1875, 0.125, 0.875, 0.25, 0.875);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.3125, 0.25, 0.3125, 0.6875, 0.75, 0.6875);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.25, 0.75, 0.25, 0.75, 0.8125, 0.75);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.1875, 0.8125, 0.1875, 0.8125, 0.875, 0.8125);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->aabb = AABB(0.125, 0.875, 0.1875, 0.1875, 1.25, 0.8125);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.1875, 0.875, 0.125, 0.8125, 1.25, 0.1875);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.8125, 0.875, 0.1875, 0.875, 1.25, 0.8125);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->aabb = AABB(0.1875, 0.875, 0.8125, 0.8125, 1.25, 0.875);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	tess->renderTexture = false;
}
