#include "Cube.h"
#include <iostream>
#include <fstream>
//#include <string>
//#include "Structures.h"

Vertex * Cube::indexedVertices = nullptr;
Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;


Cube::Cube(float x, float y, float z)
{
    _rotation = 0.0f;
    _position.x = x;
    _position.y = y;
    _position.z = z;

}

Cube::Cube()
{
    //hi
}

Cube::~Cube()
{
}
/*
bool Cube::Load(char* path)
{
    std::ifstream inFile;
    inFile.open(path);

    if (!inFile.good())
    {
        std::cerr << "Can't open text file " << path << std::endl;
        return false;
    }

    // --- Vertices ---
    inFile >> numVertices;
    indexedVertices = new Vertex[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        inFile >> indexedVertices[i].x
            >> indexedVertices[i].y
            >> indexedVertices[i].z;
    }

    // --- Colors ---
    inFile >> numColors;
    indexedColors = new Color[numColors];
    for (int i = 0; i < numColors; i++)
    {
        inFile >> indexedColors[i].r
            >> indexedColors[i].g
            >> mesh[i].b;
    }

    // --- Indices ---
    inFile >> numIndices;
    indices = new GLushort[numIndices];
    for (int i = 0; i < numIndices; i++)
    {
        inFile >> indices[i];
    }

    inFile.close();
    return true;
}
*/

void Cube::Draw()
{
    if (_mesh == nullptr)
    {
        return;  // Safety check
    }

    if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices); 
        glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
        glPushMatrix();
        glTranslatef(_position.x, _position.y, _position.z);
        glRotatef(_rotation, 1.0f, 0.0f, 0.0f); 
        glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
}

void Cube::Update()
{
    _rotation += 2.5f;
}