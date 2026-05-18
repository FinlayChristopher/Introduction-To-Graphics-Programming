#include "Texture2D.h"
#include <fstream>
using namespace std;

Texture2D::Texture2D() 
{
    _ID = 0;
    _width = 0;
    _height = 0;
}

Texture2D::~Texture2D() 
{
    // Tell OpenGL to free the GPU memory for this texture
    glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height) 
{
    _width = width;
    _height = height;

    // --- 1. Read the raw pixel data from disk ---
    ifstream inFile;
    inFile.open(path, ios::binary); // binary mode — no newline translation
    if (!inFile.good()) 
    {
        return false; // File not found or unreadable
    }

    // A .raw file is just width * height pixels, 3 bytes each (R, G, B)
    int dataSize = width * height * 3;
    char* tempTextureData = new char[dataSize];
    inFile.read(tempTextureData, dataSize);
    inFile.close();

    // --- 2. Generate an OpenGL texture ID ---
    glGenTextures(1, &_ID);          // Ask OpenGL for 1 texture name
    glBindTexture(GL_TEXTURE_2D, _ID); // Make it the active 2D texture

    // --- 3. Upload pixel data to the GPU ---
    gluBuild2DMipmaps(
        GL_TEXTURE_2D,    // target
        3,                // internal format (3 = RGB channels)
        width, height,    // dimensions
        GL_RGB,           // pixel format of source data
        GL_UNSIGNED_BYTE, // data type of each channel
        tempTextureData   // pointer to the raw data
    );

    // Set filtering so OpenGL knows how to scale the texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // --- 4. Free the CPU-side copy — we no longer need it ---
    delete[] tempTextureData;

    return true;
}