#include <iostream>
#include <fstream>
#include "Cube.h"
#include "Structures.h"

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z)
    : SceneObject(mesh, texture)
{
    _rotation = 0.0f;
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _mesh = mesh;
}

Cube::~Cube()
{
}

void Cube::Draw()
{   
    if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
    {  
        glBindTexture(GL_TEXTURE_2D, _texture->GetID());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices); 
        glColorPointer(3, GL_FLOAT, 0, _mesh->Colors); 
        glPushMatrix();
        glTranslatef(_position.x, _position.y, _position.z);
        glRotatef(_rotation, 1.0f, 0.0f, 0.0f); 
        glDrawElements(GL_TRIANGLES, (GLsizei)_mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
        glPopMatrix();
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
}

void Cube::Update()
{
    _rotation += 2.5f;
}