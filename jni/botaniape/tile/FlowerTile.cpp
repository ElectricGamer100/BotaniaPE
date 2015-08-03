#include "FlowerTile.h"

#include "minecraftpe/level/TileSource.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/ParticleType.h"
#include "minecraftpe/util/Vec3.h"

FlowerTile* FlowerTile::puredaisy = NULL;
FlowerTile* FlowerTile::mysticalFlower = NULL;

FlowerTile::FlowerTile(int blockId, std::string const& texture, Material const* material) : Tile(blockId, texture, material) {
	//init();
	blockRendererId = 1;
	lightBlock[blockId] = 0;
	setSoundType(Tile::SOUND_GRASS);
	setExplodeable(0.0);
	setDestroyTime(0.0);
	setCategory(1);
	setTicking(true);
	
	Tile::solid[blockId] = false;
	
	new TileItem(blockId - 256);
}

bool FlowerTile::isPathfindable(TileSource* ts, int x, int y, int z){
	return true;
}

void FlowerTile::addAABBs(TileSource* ts, int x, int y, int z, const AABB* aabb, std::vector<AABB> &vaabb){
	aabb = new AABB(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
}
