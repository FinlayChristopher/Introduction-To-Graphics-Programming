#pragma once
#include "SceneObject.h"

class Pyramid : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
public:
	//Pyramid(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	//static bool Load(char* path);

	void Draw();
	void Update();
};