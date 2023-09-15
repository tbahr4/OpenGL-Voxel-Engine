//
// Blocks.cpp
// 
// Defines all available blocks
//
#include "Blocks.h"
TextureAtlas Blocks::textures;

// init
// Initializes block data
//
void Blocks::init() {
	// Init atlas
	textures = TextureAtlas("assets/textures/blocks.png", 32);
}

// getAtlasTextureID
// Returns the texture ID referenced by the atlas
//
int Blocks::getAltasTextureID() {
	return textures.getTextureID();
}

// getAtlasMaxTextures
// Returns the max number of textures that may fit in the atlas
//
int Blocks::getAtlasMaxTextures() {
	return textures.size();
}

// Block names
//
string Blocks::name[] = {
	"None",
	"Grass",
	"Dirt",
	"Stone",
};

