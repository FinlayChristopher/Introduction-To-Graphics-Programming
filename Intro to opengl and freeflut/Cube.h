#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"


class Cube
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;
	Mesh* _mesh;

	//static Vertex vertices[];
	//static Colour colours[];

	GLfloat _rotation;
	Vector3 _position;
	
public:
	Cube();
	~Cube();
	Cube(Mesh* mesh, float x, float y, float z);

	static bool Load(char* path);

	void Draw();
	void Update();

	//void SetRotation(float rotation);

};