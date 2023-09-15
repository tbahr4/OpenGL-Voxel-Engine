//
// Engine.h
// 
// Used to create an OpenGL instance for rendering
//
#pragma once

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Camera.h"
#include "World.h"
#include "Shapes.h"
#include "Logger.h"
using namespace std;
using namespace glm;


class Engine
{
private:
	// Frame timings
	float deltaTime = 0.0f;			// Time between current and last frame
	float lastFrame = 0.0f;

	// Voxels
	float voxelSizeMultiplier;

public:
	GLFWwindow* window;				// Create new window
	Camera* camera;					// Create new camera
	Shader* shader;					// Create new shader object
	World* world;					// Create new world object
	Shapes* shapes;					// Create new shapes object	(generates vertex arrays)
	int screenWidth, screenHeight;
	bool firstMouseFocus = true;	// Remains true until mouse becomes focused in window
	float prevX, prevY;				// Last mouse movement position
	unsigned int VAO, VBO;			// Vertex objects
	vec3 backgroundColor;
	vec3 defaultVoxelColor;


public:
	// Constructors
	//

	// Initialize the engine
	Engine(const char* windowTitle, int screenWidth, int screenHeight, vec3 initialCamPos, float camYaw, float camPitch, float movementSpeed, float mouseSensitivity, float fov, vec3 backgroundColor, vec3 defaultVoxelColor, float voxelSizeMultiplier);

	void processKeyboardInput(GLFWwindow* window);		// Processes keyboard inputs
	bool loop();	// To be called every frame; Returns false if window has been signaled to close
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);		// Called whenever the screen is resized
void mouse_callback(GLFWwindow* window, double xpos, double ypos);				// Processes mouse inputs