#include "Puredaisy.h"

#include "minecraftpe/level/TileSource.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/level/ParticleType.h"
#include "minecraftpe/util/Vec3.h"

int puredaisy_ID;

Puredaisy::Puredaisy(int id, std::string const& texture, Material const* material) : FlowerTile(id, texture, material){
	init();
	puredaisy_ID = id;
	setNameId("puredaisy");
}

int Puredaisy::getResource(int id, Random* random){
	return puredaisy_ID;
}

int Puredaisy::getResourceCount(Random* random){
	return 1;
}

void Puredaisy::animateTick(TileSource* tilesource, int x, int y, int z, Random* random) {
	Level* level = tilesource->getLevel();
	level->addParticle(ParticleType::PARTICLE_FLAME, Vec3((float) x+0.5, (float) y+0.5, (float) z+0.5), Vec3(0.0, 0.0, 0.0), 8);
	//is it possible to make custom particles?
}
