//
// World.h
// 
// Handles the position vector for each voxel, and
// supports voxel creation and property edits
//
#include "World.h"



// Constructors
//
World::World(vec3 defaultVoxelColor, float voxelSizeMultiplier) {
	this->defaultVoxelColor = defaultVoxelColor;
	this->voxelSizeMultiplier = voxelSizeMultiplier;
}

// Voxel modification
//

// addBlock
//
// Adds a block to the world
//
void World::addBlock(vec3 position, Blocks::ID blockID) {
	if (blockID == Blocks::ID::none) return;

	// Position
	blockPositions.push_back(position * voxelSizeMultiplier);

	// Properties
	blockProperties.push_back(BlockProperties(defaultVoxelColor, blockID));

	if (blockPositions.size() != blockProperties.size()) {
		Logger::log(Logger::FATAL, "Block positions/properties vector at invalid size");
	}
}

// Accessor functions
//

// getBlockCount
// Returns the number of blocks placed in the world
//
int World::getBlockCount() const {
	return (int)blockPositions.size();
}

// getPositionVector
// Returns the block position vector
//
vector<vec3>& World::getPositionVector() {
	return blockPositions;
}

// getPropertiesVector
// Returns the block properties vector
//
vector<BlockProperties>& World::getPropertiesVector() {
	return blockProperties;
}