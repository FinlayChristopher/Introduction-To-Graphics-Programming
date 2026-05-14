#include "SceneObject.h"
#include "Texture2D.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture) : _mesh(mesh), _texture(texture) 
{
}

SceneObject::~SceneObject()
{
}

void SceneObject::Draw()
{
    // base implementation empty - overridden by child classes
}

void SceneObject::Update()
{
}