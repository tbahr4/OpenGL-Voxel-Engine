//
// TextureAtlas.h
// 
// Stores a list of textures
//
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Logger.h"
using namespace std;
using namespace glm;


class TextureAtlas
{
private:
	struct Texture {
		int xOffset, yOffset;		// The offset from the top-left texture in the atlas

		Texture(int x, int y) {
			xOffset = x;
			yOffset = y;
		}
	};

	int textureID;		// Texture id referenced by openGL	
	int textureSize;	// The size of each texture
	int width;			// The size of the atlas image (must be same as height)
	int maxTextures;	// The maximum number of available textures

	map<string, int> imageIndex;	// Maps image names to their index in the atlas

	

public:
	// Constructors
	TextureAtlas() = default;
	TextureAtlas(const char* imagePath, int textureSize, vector<pair<string,int>> imageLocations);

	// Other functions
	vec2 getTextureCoords(int textureIndex);	// Returns the texture coords given an index
	vec2 getTextureCoords(string imageName);	// Return the texture coords given an image name
	int size() const;				// Returns max number of available textures
	int getTextureID() const;		// Returns texture ID of the atlas

private:
	bool generateAtlas(const char* imagePath, int& atlasWidth, int& atlasHeight);	// Generates a texture atlas from a given path to the atlas image
};

