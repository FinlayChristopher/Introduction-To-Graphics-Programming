#pragma once
#include "Structures.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
public:
	virtual void Draw();
	virtual void Update();
	SceneObject(Mesh* mesh, Texture2D* texture);
};