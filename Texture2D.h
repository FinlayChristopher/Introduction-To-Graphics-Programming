#pragma once
#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

class Texture2D
{
private:
    GLuint _ID;        // The OpenGL handle to the texture on the GPU
    int _width;
    int _height;

public:
    Texture2D();
    ~Texture2D();

    bool Load(char* path, int width, int height);

    GLuint GetID() const { return _ID; }
    int    GetWidth() const { return _width; }
    int    GetHeight() const { return _height; }
};