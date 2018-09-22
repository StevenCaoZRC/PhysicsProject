//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	main.cpp
// Description	:	main implementation for program
// Author		:	Steven Cao
// Mail			:	steven.zha7447@mediadesign.school.nz
//

// Library Includes //
#include <iostream>

// Local Includes //
#include "Camera.h"
#include "Entity.h"
#include "SceneManager.h" 
#include "Controls.h"
#include "Scene.h"
#include "Interface.h"
#include "Sound.h"
#include "Utility.h"
#include "Time.h"

// Types //
using namespace std;

// Prototypes //
void Update();
void render();
void exit();
int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Utility::SCR_WIDTH, Utility::SCR_HEIGHT);
	glutCreateWindow("My Game");

	glewInit();
	CSceneManager::GetInstance()->init();


	glutDisplayFunc(render);
	glutIdleFunc(Update);
	glutCloseFunc(exit);
	glutMainLoop();

	//CSceneManager::DestroyInstance();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 1.0, 0.0, 1.0);//clears a colour
	CSceneManager::GetInstance()->RenderCurrent();
	//cout << "rendering" << endl;
	//CInterface::GetInstance()->render();
	glutSwapBuffers();
}
void exit()
{
	CSceneManager::DestroyInstance();
	CCamera::DestroyInstance();
	CControls::DestroyInstance();
	CInterface::DestroyInstance();
	CSound::DestroyInstance();

}
void Update()
{
	// Update game information.
	glutPostRedisplay(); //render function is called
	CTime::GetInstance()->Update();

	//CInterface::GetInstance()->update();
	CSceneManager::GetInstance()->UpdateCurrent();
	//CControls::GetInstance()->update();
}