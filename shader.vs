#version 330 core
layout (location = 0) in vec3 aPos;					// Position of the vertex
layout (location = 1) in vec2 aTextureCoord;		// Texture coordinate at this vertex (0-1)
layout (location = 2) in vec3 aNormal;				// Normal (facing direction) of this vertex's designated face

out vec2 TextureCoord;
out vec3 Normal;

uniform mat4 model;				// Translations scaling and rotations we'd like to apply to transform ALL objects vertices to the global world space
uniform mat4 view;				// Camera view
uniform mat4 projection;		// Map of 3d coordinates to 2d screen
uniform vec2 TextureOffsets[6];		// The actual offset to get to each of the texture's sides 
uniform float TextureSize;		// Value between 0f-1f specifying the space in the atlas that the texture is occupying

void main() 
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	Normal = aNormal;

	
	// Texturing
	vec2 TextureOffset;
	if (Normal.x == 0 && Normal.y == 0 && Normal.z > 0) TextureOffset = TextureOffsets[0];		// Front
	else if (Normal.x < 0 && Normal.y == 0 && Normal.z == 0) TextureOffset = TextureOffsets[1];	// Left
	else if (Normal.x == 0 && Normal.y == 0 && Normal.z < 0) TextureOffset = TextureOffsets[2];	// Back
	else if (Normal.x > 0 && Normal.y == 0 && Normal.z == 0) TextureOffset = TextureOffsets[3];	// Right
	else if (Normal.x == 0 && Normal.y > 0 && Normal.z == 0) TextureOffset = TextureOffsets[4];	// Top
	else if (Normal.x == 0 && Normal.y < 0 && Normal.z == 0) TextureOffset = TextureOffsets[5];	// Bottom

	TextureCoord = vec2(TextureOffset.x + (aTextureCoord.x * TextureSize), 1 - TextureOffset.y - TextureSize + (aTextureCoord.y * TextureSize));
}