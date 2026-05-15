#pragma once
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	GLfloat _rotation;
	Vector3 _position;
public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	//static bool Load(char* path);

	void Draw();
	void Update();

	//void SetRotation(float rotation);
};