#include "HelloGL.h"
//#include "Cube
#include "Structures.h"
#include <string>

#include <iostream> 

//Testing to see if works with Teapot:
#include <fstream>  
#include <sstream> 
#include <vector>   
void InitObjects()
{
    camera = new Camera();
    Cube::Load((char*)"cube.txt");
    //cube = new Cube();
    for (int i = 0; i < 200; i++)
    {
        cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
    }

    camera->eye.x = 0.0f; camera->eye.y = 10.0f; camera->eye.z = 30.0f;
    //camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
    camera->centre.x = 0.0f; camera->centre.y = 0.0f; camera->centre.z = 0.0f;
    camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

    rotation = 0.0f;
}
void InitGL(int argc, char* argv[])
{
    std::string windowName = "OpenGL Project for Graphics Programming"; 

    // Positioning window position to the centre
    int windowPositionX = 0;
    int windowPositionY = 0;

    GLUTCallbacks::Init(this);
    glutInit(&argc, argv);

    glutInitWindowSize(800, 800);
    glutInitWindowPosition(windowPositionX, windowPositionY);
    glutCreateWindow(windowName.c_str());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, 800, 800);
    gluPerspective(45, 1, 1, 1000);
    glEnable(GL_DEPTH_TEST);
    //FOV = 45, 1 is the aspect ratio, 0 is the near plane, 1000 is the far plane
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(GLUTCallbacks::Display);
    glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
    glutKeyboardFunc(GLUTCallbacks::Keyboard);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

HelloGL::HelloGL(int argc, char* argv[]) // constructor - double check in tutorial 2
{
    glutMainLoop();
    _mesh = mesh;
}

void HelloGL::Display()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //GL_COLOR_BUFFER_BIT and GL_DEPTH_BUFFER_BIT are different types of buffers. -> https://learnopengl.com/Advanced-OpenGL/Depth-testing
    for (int i = 0; i < 200; i++)
    {
        cube[i]->Draw();
    }
    glPushMatrix();
    glPopMatrix();
    glFlush(); //Flushes the scene drawn to the graphics card    
    glutSwapBuffers(); //Swaps buffers positions.
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
}


HelloGL::~HelloGL(void)
{

}

void HelloGL::Update()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    for (int i = 0; i < 200; i++)
    {
        cube[i]->Update();
    }
    
    glLoadIdentity();
    gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera -> centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
    glutPostRedisplay();
    rotation += 0.5f;
    if (rotation >= 360.0f)
    {
        rotation = 0.0f;
    }

    float* ptr = &rotation;
    
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
    //figure out logic
    if (key == 'a' or key == 'd')
    {
        if (key == 'a')
        {
            rotation += 5.0;
        }
        if (key == 'd')
        {

            rotation -= 5.0;
        }
    }
    
}