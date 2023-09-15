//
// Camera.h
// 
// Used by the engine to handle camera positioning and movement
//
#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

using namespace glm;

enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
	// Camera attributes
	vec3 position;
	vec3 front;
	vec3 up;
	vec3 right;
	vec3 worldUp = vec3(0.0f, 1.0f, 0.0f);
	// Euler angles
	float yaw;
	float pitch;
	// Camera options
	float movementSpeed;
	float mouseSensitivity;
	float fov;


	// Constructors
	Camera(vec3 position, float yaw, float pitch, float movementSpeed, float mouseSensitivity, float fov);

	// Camera-specific inputs
	void ProcessKeyboard(CameraMovement direction, float deltaTime);		
	void ProcessMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);

	// Other functions
	glm::mat4 GetViewMatrix();		// returns the view matrix calculated using Euler Angles and the LookAt Matrix

private:
	void updateCameraVectors();		// calculates the front vector from the Camera's (updated) Euler Angles
};