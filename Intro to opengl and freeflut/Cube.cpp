#include "Cube.h"
#include <iostream>
#include <fstream>
#include "SceneObject.h"
#include "Structures.h"

//Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
//GLushort* Cube::indices = nullptr;
//
//int Cube::numVertices = 0;
//int Cube::numColors = 0;
//int Cube::numIndices = 0;

/*
Vertex Cube::indexedVertices[] = { 1, 1, 1, -1, 1, 1, // v0,v1,
 -1,-1, 1, 1,-1, 1, // v2,v3
1,-1,-1, 1, 1,-1, // v4,v5
-1, 1,-1, -1,-1,-1 }; // v6,v7
Colour Cube::indexedColors[] = { 1, 1, 1, 1, 1, 0, // v0,v1,
1, 0, 0, 1, 0, 1, // v2,v3
0, 0, 1, 0, 1, 1, // v4,v5
0, 1, 0, 0, 0, 0 }; //v6,v7
GLushort Cube::indices[] = { 0, 1, 2, 2, 3, 0, // front
0, 3, 4, 4, 5, 0, // right
0, 5, 6, 6, 1, 0, // top
1, 6, 7, 7, 2, 1, // left
7, 4, 3, 3, 2, 7, // bottom
4, 7, 6, 6, 5, 4 }; // back*/

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
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

void Cube::Update()
{
    _rotation += 2.5f;
}
