#include "PetalApothecary.h"

PetalApothecary* PetalApothecary::petalApothecary = NULL;

PetalApothecary::PetalApothecary(int id, Material const* material) : Tile(id, material){
	init();
	lightBlock[id] = 0;
	setNameId("petalApothecary");
	Tile::solid[id] = false;
	new TileItem(id - 256);
}
