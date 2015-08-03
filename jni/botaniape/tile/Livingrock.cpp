#include "Livingrock.h"

Livingrock* Livingrock::livingrock = NULL;

Livingrock::Livingrock(int id, std::string const& texture, Material const* material) : Tile(id, texture, material) {
	init();
	setNameId("livingrock");
	
	new TileItem(id - 256);
}
