#include "HelloGL.h"
#include "Cube.h"
#include "Structures.h"
#include "MeshLoader.h"
#include <string>


void HelloGL::InitObjects()
{
    camera = new Camera();
    
    Mesh* cubeMesh = MeshLoader::Load((char*)"pyramid.txt");
    for (int i = 0; i < 200; i++)
    {
        cube[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
    }

    camera->eye.x = 0.0f; camera->eye.y = 10.0f; camera->eye.z = 30.0f;
    camera->centre.x = 0.0f; camera->centre.y = 0.0f; camera->centre.z = 0.0f;
    camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

    rotation = 0.0f;
}

void HelloGL::InitGL(int argc, char* argv[])
{
    std::string windowName = "OpenGL Project for Graphics Programming"; 

    int windowPositionX = 0;
    int windowPositionY = 0;

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

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
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(GLUTCallbacks::Display);
    glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
    glutKeyboardFunc(GLUTCallbacks::Keyboard);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

HelloGL::HelloGL(int argc, char* argv[])
{
    InitGL(argc, argv);
    InitObjects();
    glutMainLoop();
}

void HelloGL::Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (int i = 0; i < 200; i++)
    {
        cube[i]->Draw();
    }
    glFlush();
    glutSwapBuffers();
}

HelloGL::~HelloGL(void)
{
}

void HelloGL::Update()
{
    for (int i = 0; i < 200; i++)
    {
        cube[i]->Update();
    }
    
    glLoadIdentity();
    gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
    glutPostRedisplay();
    rotation += 0.5f;
    if (rotation >= 360.0f)
    {
        rotation = 0.0f;
    }
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
    if (key == 'a' || key == 'd')
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