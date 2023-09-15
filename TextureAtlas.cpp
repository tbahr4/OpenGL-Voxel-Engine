//
// TextureAtlas.cpp
// 
// Stores a list of textures
//
#include "TextureAtlas.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


// Constructor
// Loads an atlas of textures from an image path and provided size of each texture
//
TextureAtlas::TextureAtlas(const char* img, int textureSize) {
	int atlasWidth, atlasHeight;
	if (!generateAtlas(img, atlasWidth, atlasHeight)) {
		Logger::log(Logger::WARNING, "Texture atlas unable to be generated");
		this->textureID = -999;
		return;
	}
	if (atlasWidth != atlasHeight) {
		Logger::log(Logger::WARNING, "Texture atlas width must match its height");
		this->textureID = -999;
		return;
	}
	if (atlasWidth % textureSize != 0 || atlasHeight % textureSize != 0) {
		Logger::log(Logger::WARNING, "Invalid texture size");
		this->textureID = -999;
		return;
	}

	this->width = atlasWidth;
	this->textureSize = textureSize;
	this->maxTextures = (atlasWidth / textureSize) * (atlasHeight / textureSize);
}


// getTextureCoords
// Returns the texture coords given an index
//
vec2 TextureAtlas::getTextureCoords(int textureIndex) {
	if (textureIndex < 0 || textureIndex >= maxTextures) {
		Logger::log(Logger::FATAL, "Attempting to access invalid texture coordinates");
		return vec2(-999, -999);
	}

	int texturesPerRow = (int)sqrt(this->maxTextures);
	int x = textureIndex % texturesPerRow;
	int y = textureIndex / texturesPerRow;

	// Scale to 0f-1f
	float xAdj = float(x) / float(texturesPerRow);
	float yAdj = float(y) / float(texturesPerRow);

	return vec2(xAdj, yAdj);
}


// size
// Returns max number of available textures
//
int TextureAtlas::size() const {
	return this->maxTextures;
}

// getTextureID
// Returns texture ID of the atlas
//
int TextureAtlas::getTextureID() const {
	return this->textureID;
}


// Helper functions
//

// generateAtlas
// Generates a texture atlas from a given path to the atlas image
// Returns true on success
//
bool TextureAtlas::generateAtlas(const char* imagePath, int& atlasWidth, int& atlasHeight) {
	// Create the texture
	unsigned int texture;
	glGenTextures(1, &texture);
	if (texture < 0) {
		Logger::log(Logger::WARNING, "Texture generation failed");
		return false;
	}
	glBindTexture(GL_TEXTURE_2D, texture);

	// Texture wrapping/filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load texture
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);  
	unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		Logger::log(Logger::WARNING, "Texture load failed");
		return false;
	}
	stbi_image_free(data);

	textureID = texture;
	atlasWidth = width;
	atlasHeight = height;
	return true;
}