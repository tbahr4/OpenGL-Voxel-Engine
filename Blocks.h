//
// Blocks.h
// 
// Defines all available blocks
//
#pragma once
#include <string>
#include <algorithm>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "TextureAtlas.h"
using namespace std;
using namespace glm;


class Blocks {
public:
	Blocks() = delete;

	static void init();	// Initializes block data
	
	// Block IDs
	enum ID {
		none = 0,
		grass = 1,
		dirt = 2,
		stone = 3
	};

	// Block Names
	static const string NAME(ID id) {
		return name[id];
	}

	// Block Textures
	static const vec2 TEXTURE(ID id) {
		if (id <= 0 || id > textures.size()) {
			Logger::log(Logger::WARNING, "Accessing invalid block texture");
		}
		return textures.getTextureCoords(id - 1);		// Offset by 1 to skip empty texture ID
	}

	static int getAltasTextureID();		// Returns the texture ID referenced by the atlas
	static int getAtlasMaxTextures();	// Returns the max number of textures that may fit in the atlas

private:
	static string name[];
	static TextureAtlas textures;
};

