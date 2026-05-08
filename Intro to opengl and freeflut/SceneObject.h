#pragma once
#include "Structures.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
public:
	virtual void Draw();
	virtual void Update();

	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();
};