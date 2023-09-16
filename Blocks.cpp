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
	// Initialize atlas
	vector<pair<string,int>> imageLocations = {
		make_pair("grass_top", 0),
		make_pair("dirt", 1),
		make_pair("stone", 2),

		make_pair("grass_side", 8)
	};

	textures = TextureAtlas("assets/textures/blocks.png", 32, imageLocations);
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

// Texture names
//
string Blocks::textureName[][6] = {
	{"","","","","",""},	// None
	{"grass_side","grass_side","grass_side","grass_side","grass_top","dirt"},
	{"dirt","dirt","dirt","dirt","dirt","dirt"},
	{"stone","stone","stone","stone","stone","stone"}
};


// getTextureNames
// Returns the list of textures for a given block id
//
string* Blocks::getTextureNames(ID id) {
	return textureName[(int)id];
}

