//
// Shapes.cpp
// 
// Generates vertex arrays used to render shapes
//
#include "Shapes.h"


// Constructor
// Generates each vertex array from given size multiplier
//
Shapes::Shapes(float sizeMultiplier) {
	// Size check
	if (sizeMultiplier <= 0) throw out_of_range("ERROR::SHAPES\nsizeMultiplier out of range");
	if (sizeMultiplier == 1) return;		// No change

	// Adjust size
	for (size_t i = 0; i < CUBE_TOTAL_ATTRIBUTES; i += CUBE_ATTRIBUTES_PER_LINE) {
		cubeVertices[i] *= sizeMultiplier;
		cubeVertices[i + 1] *= sizeMultiplier;
		cubeVertices[i + 2] *= sizeMultiplier;
	}
}


// Accessor functions
//

vector<float>& Shapes::cube() {
	return cubeVertices;
}