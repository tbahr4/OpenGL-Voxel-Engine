//
// World.h
// 
// Handles the position vector for each voxel,
// supports voxel creation and voxel property edits
//
#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <string>
#include <iostream>
#include "Blocks.h"
using namespace std;
using namespace glm;


// blockProperty
// Stores the properties of each voxel
//
struct BlockProperties {
	vec3 color;
	Blocks::ID id;

	BlockProperties(vec3 color, Blocks::ID id) {
		this->color = color;
		this->id = id;
	}
};


class World
{
private:
	vec3 defaultVoxelColor;
	float voxelSizeMultiplier;
	vector<vec3> blockPositions;
	vector<BlockProperties> blockProperties;

public:
	// Constructors
	//
	World(vec3 defaultVoxelColor, float voxelSizeMultiplier);

	// Voxel modification
	//
	void addBlock(vec3 position, Blocks::ID id);		// Add a block to the world

	// Accessor functions
	int getBlockCount() const;
	vector<vec3>& getPositionVector();
	vector<BlockProperties>& getPropertiesVector();
};


