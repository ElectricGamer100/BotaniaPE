#pragma once

#include "../Renderer.h"

class PetalApothecaryRender: public Renderer {
public:
	virtual void render(const TilePos&, Tile*, TileTessellator*);
};
