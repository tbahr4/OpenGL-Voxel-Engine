
#include <iostream>
#include "Engine.h"
#include "Blocks.h"
#include "Logger.h"

#define SCREEN_TITLE "Voxel Engine"
#define INITIAL_SCREEN_WIDTH 800
#define INITIAL_SCREEN_HEIGHT 600
#define INITIAL_POSITION vec3(1.0f, 1.0f, 7.0f)
#define CAM_DEFAULT_YAW -90.0f
#define CAM_DEFAULT_PITCH 0.0f
#define MOVEMENT_SPEED 5.0f
#define MOUSE_SENSITIVITY 0.15f
#define FOV 90.0f
#define BACKGROUND_COLOR vec3(0.2f, 0.3f, 0.3f)
#define DEFAULT_VOXEL_COLOR vec3(1.f, .2f, .86f)		// Invalid texture color
#define VOXEL_SIZE_MULTIPLIER 1.0f


Engine engine(SCREEN_TITLE, INITIAL_SCREEN_WIDTH, INITIAL_SCREEN_HEIGHT, INITIAL_POSITION, CAM_DEFAULT_YAW, CAM_DEFAULT_PITCH, MOVEMENT_SPEED, MOUSE_SENSITIVITY, FOV, BACKGROUND_COLOR, DEFAULT_VOXEL_COLOR, VOXEL_SIZE_MULTIPLIER);


int main() {
	engine.world->addBlock(vec3(0, 0, 0), Blocks::ID::grass);
	engine.world->addBlock(vec3(2, 0, 0), Blocks::ID::dirt);
	engine.world->addBlock(vec3(4, 0, 0), Blocks::ID::stone);


	while (engine.loop());
}

