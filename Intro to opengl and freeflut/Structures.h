#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

struct Vector3

{
    float x, y, z;
};

struct Camera

{
    Vector3 eye;
    Vector3 up;
    Vector3 centre;
};

struct Color
{
    GLfloat r, g, b;
};

struct Vertex
{
    GLfloat x, y, z;
};

struct Mesh {
    Vertex* Vertices;
    Color* Colors;
    GLushort* Indices;
    GLfloat VertexCount, ColorCount, IndexCount;
};