#include "Pyramid.h"
#include <iostream>
#include <fstream>


Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
    _rotation = 0.0f;
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

Pyramid::~Pyramid()
{
}

void Pyramid::Draw()
{
    if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
    {
        glBindTexture(GL_TEXTURE_2D, _texture->GetID());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);

        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

        glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

        glPushMatrix();
        glTranslatef(_position.x, _position.y, _position.z);
        glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
        glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }

}

void Pyramid::Update()
{
    _rotation += 2.5f;
}
