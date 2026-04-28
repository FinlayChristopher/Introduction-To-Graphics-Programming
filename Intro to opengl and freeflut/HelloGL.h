#pragma once
#include "Structures.h"
#include "GLUTCallbacks.h"
#include "Cube.h"
#define REFRESHRATE 16

class HelloGL
{
private:
    float rotation;
    Camera* camera;
    
    Cube* cube[200];
    static Vertex indexedVertices[];
    static Color indexedColors[];
	static GLushort indices[];

public:
    // Constructor definition
    HelloGL(int argc, char* argv[]);
    void InitGL(int argc, char* argv[]);
    void InitObjects();

    // Destructor
    ~HelloGL(void);

    void Display();
    
    /*void DrawCubeArray();
    void DrawIndexedCube();*/
	//void DrawPolygon();
    //void DrawTriangle();    

    void Update();

    void Keyboard(unsigned char key, int x, int y);
    
};
