//
// Shapes.h
// 
// Generates vertex arrays used to render shapes
//
#pragma once
#include <vector>
#include <stdexcept>
using namespace std;

#define CUBE_TOTAL_ATTRIBUTES 288		// Number of total attributes defined
#define CUBE_ATTRIBUTES_PER_LINE 8		// Number of values per vertex line



class Shapes
{
public:
	// Constructors
	Shapes(float sizeMultiplier);		// Generates each vertex array from given size multiplier

	// Accessor functions
	vector<float>& cube();

private:
	// Vertices to generate a cube
	//
	vector<float> cubeVertices = {
		// Vertex positions		// Texture coords		// Normal	
		//						//					    //
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f,				0.0f, 0.0f, -1.0f,		// Back
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f,				0.0f, 0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f,				0.0f, 0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f,				0.0f, 0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f,				0.0f, 0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 1.0f,				0.0f, 0.0f, -1.0f,

		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,				0.0f, 0.0f, 1.0f,		// Front
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,				0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,				0.0f, 0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,				0.0f, 0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f,				0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,				0.0f, 0.0f, 1.0f,

		-0.5f,  0.5f,  0.5f,	1.0f, 1.0f,			   -1.0f, 0.0f, 0.0f,		// Left
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,			   -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,			   -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,			   -1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f,			   -1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 1.0f,			   -1.0f, 0.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f,				1.0f, 0.0f, 0.0f,		// Right
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,				1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,				1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,				1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f,				1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f,				1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,				0.0f, -1.0f, 0.0f,		// Bottom
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,				0.0f, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 1.0f,				0.0f, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 1.0f,				0.0f, -1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f,				0.0f, -1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,				0.0f, -1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,				0.0f, 1.0f, 0.0f,		// Top
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,				0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,				0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,				0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 			0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f,				0.0f, 1.0f, 0.0f
		
	};
};