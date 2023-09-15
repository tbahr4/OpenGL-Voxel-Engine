//
// Shader.h
// 
// Abstracts vertex and fragment shaders behind
// this class. Uses files for shader access
//
#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include "Logger.h"
using namespace std;
using namespace glm;


class Shader
{
public:
	unsigned int ID;	// Shader program ID

	// Constructors
	//
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	void use();		// Activate the shader

	// Uniform Functions
	//

	// Set uniform values
	void setBool(const string& name, bool value) const;
	void setInt(const string& name, int value) const;
	void setFloat(const string& name, float value) const;
	void setMat4(const string& name, mat4 mat) const;
	void setVec2(const string& name, vec2 vec) const;
	void setVec3(const string& name, vec3 vec) const;
	void setVec4(const string& name, vec4 vec) const;
};
