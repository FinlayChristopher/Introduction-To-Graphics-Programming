#pragma once
#include "Structures.h"

class Cube
{
private:
	//static Vertex* indexedVertices;
	//static Color* indexedColors;
	//static GLushort* indices;
	//static int numVertices, numColors, numIndices;

	//static Vertex vertices[];
	//static Colour colours[];

	Mesh* _mesh;
	GLfloat _rotation;
	Vector3 _position;
	
public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	//static bool Load(char* path);

	void Draw();
	void Update();

	//void SetRotation(float rotation);

};