<<<<<<< HEAD
//#include "Texture2D.h"
//#include <fstream>
//using namespace std;
//
//Texture2D::Texture2D() {
//    // Nothing needed — _ID will be set by Load()
//}
//
//Texture2D::~Texture2D() {
//    // Tell OpenGL to free the GPU memory for this texture
//    glDeleteTextures(1, &_ID);
//}
//
//bool Texture2D::Load(char* path, int width, int height) {
//    _width = width;
//    _height = height;
//
//    // --- 1. Read the raw pixel data from disk ---
//    ifstream inFile;
//    inFile.open(path, ios::binary); // binary mode — no newline translation
//    if (!inFile.good()) {
//        return false; // File not found or unreadable
//    }
//
//    // A .raw file is just width * height pixels, 3 bytes each (R, G, B)
//    int dataSize = width * height * 3;
//    char* tempTextureData = new char[dataSize];
//    inFile.read(tempTextureData, dataSize);
//    inFile.close();
//
//    // --- 2. Generate an OpenGL texture ID ---
//    glGenTextures(1, &_ID);          // Ask OpenGL for 1 texture name
//    glBindTexture(GL_TEXTURE_2D, _ID); // Make it the active 2D texture
//
//    // --- 3. Upload pixel data to the GPU ---
//    glTexImage2D(
//        GL_TEXTURE_2D,    // target
//        0,                // mipmap level (0 = base)
//        3,                // internal format (3 = RGB channels)
//        width, height,    // dimensions
//        0,                // border (must be 0)
//        GL_RGB,           // pixel format of source data
//        GL_UNSIGNED_BYTE, // data type of each channel
//        tempTextureData   // pointer to the raw data
//    );
//
//    // Set filtering so OpenGL knows how to scale the texture
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    // --- 4. Free the CPU-side copy — we no longer need it ---
//    delete[] tempTextureData;
//
//    return true;
//}
//
//bool Texture2D::LoadBMP(char* path) {
//    ifstream file(path, ios::binary);
//    if (!file.good()) return false;
//
//    // BMP header is 54 bytes
//    char header[54];
//    file.read(header, 54);
//
//    // Extract width and height from known byte offsets in the header
//    _width = *(int*)&header[18]; // bytes 18–21
//    _height = *(int*)&header[22]; // bytes 22–25
//
//    int dataSize = _width * _height * 3;
//    char* data = new char[dataSize];
//    file.read(data, dataSize);
//    file.close();
//
//    // BMP stores pixels as BGR, not RGB — swap if needed
//    for (int i = 0; i < dataSize; i += 3) {
//        char temp = data[i];
//        data[i] = data[i + 2]; // B -> R position
//        data[i + 2] = temp;        // R -> B position
//    }
//
//    glGenTextures(1, &_ID);
//    glBindTexture(GL_TEXTURE_2D, _ID);
//    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _width, _height,
//        GL_RGB, GL_UNSIGNED_BYTE, data);
//
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    delete[] data;
//    return true;
//}//}
=======
#include "Texture2D.h"
#include <fstream>
using namespace std;

Texture2D::Texture2D() {
    // Nothing needed ï¿½ _ID will be set by Load()
}

Texture2D::~Texture2D() {
    // Tell OpenGL to free the GPU memory for this texture
    glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height) {
    _width = width;
    _height = height;

    // --- 1. Read the raw pixel data from disk ---
    ifstream inFile;
    inFile.open(path, ios::binary); // binary mode ï¿½ no newline translation
    if (!inFile.good()) {
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
    glTexImage2D(
        GL_TEXTURE_2D,    // target
        0,                // mipmap level (0 = base)
        3,                // internal format (3 = RGB channels)
        width, height,    // dimensions
        0,                // border (must be 0)
        GL_RGB,           // pixel format of source data
        GL_UNSIGNED_BYTE, // data type of each channel
        tempTextureData   // pointer to the raw data
    );

    // Set filtering so OpenGL knows how to scale the texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // --- 4. Free the CPU-side copy ï¿½ we no longer need it ---
    delete[] tempTextureData;

    return true;
}
>>>>>>> parent of a870d16 (2)
