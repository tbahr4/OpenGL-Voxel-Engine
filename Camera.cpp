//
// Camera.cpp
// 
// Used by the engine to handle camera positioning and movement
//
#include "Camera.h"


// Camera constructor
//
Camera::Camera(vec3 position, float yaw, float pitch, float movementSpeed, float mouseSensitivity, float fov) {
	this->movementSpeed = movementSpeed;
	this->mouseSensitivity = mouseSensitivity;
	this->fov = fov;
	this->position = position;
	this->yaw = yaw;
	this->pitch = pitch;
	updateCameraVectors();
}

// GetViewMatrix
// returns the view matrix calculated using Euler Angles and the LookAt Matrix
//
glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(position, position + front, up);
}

// ProcessKeyboard
// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
//
void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime) {
	float velocity = movementSpeed * deltaTime;
	if (direction == FORWARD)
		position += front * velocity;
	if (direction == BACKWARD)
		position -= front * velocity;
	if (direction == LEFT)
		position -= right * velocity;
	if (direction == RIGHT)
		position += right * velocity;
}

// ProcessMouseMovement
// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
//
void Camera::ProcessMouseMovement(float xOffset, float yOffset, GLboolean constrainpitch) {
	xOffset *= mouseSensitivity;
	yOffset *= mouseSensitivity;

	yaw += xOffset;
	pitch += yOffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainpitch) {
		if (pitch > 89.0f) pitch = 89.0f;
		if (pitch < -89.0f) pitch = -89.0f;
	}

	// update front, right and up Vectors using the updated Euler angles
	updateCameraVectors();
}

// updateCameraVectors
// updates the front vector from the Camera's current Euler Angles
//
void Camera::updateCameraVectors() {
	// calculate the new front vector
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(newFront);
	// also re-calculate the right and up vector
	right = glm::normalize(glm::cross(front, worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, front));
}