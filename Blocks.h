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
	static const vector<vec2> TEXTURE(ID id) {
		if (id <= 0 || id > textures.size()) {
			Logger::log(Logger::WARNING, "Accessing invalid block texture");
		}

		auto textureNames = getTextureNames(id);
		vector<vec2> coordList(6);
		for (int i = 0; i < 6; i++) {
			coordList[i] = textures.getTextureCoords(textureNames[i]);
		}

		return coordList;
	}

	static int getAltasTextureID();		// Returns the texture ID referenced by the atlas
	static int getAtlasMaxTextures();	// Returns the max number of textures that may fit in the atlas

private:
	static string name[];
	static string textureName[][6];
	static TextureAtlas textures;

	static string* getTextureNames(ID id);		// Returns the list of textures for a given block id
};

