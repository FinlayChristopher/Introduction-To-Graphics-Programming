#pragma once
#include "Structures.h"

class SceneObject
{
protected:
	Mesh* _mesh;
public:
	virtual void Draw();
	virtual void Update();
	SceneObject(Mesh* mesh);
};