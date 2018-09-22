//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	SceneManager.cpp
// Description	:	main implementation for SceneManager
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// Library Includes //

// Local Includes //
//#include "Sound.h"
// This Includes //
#include "SceneManager.h"
#include "Level.h"
// Types //
using namespace std;
CSceneManager* CSceneManager::pSceneManager; // Redefining the static variable for class

CSceneManager * CSceneManager::GetInstance()
{
	if (!pSceneManager) // If this does not exist
	{
		pSceneManager = new CSceneManager(); //Create an instance of SceneManager
	}

	return pSceneManager;	//Returns the static instance
}

void CSceneManager::DestroyInstance()
{
	if (pSceneManager) //If the instance exists
	{
		delete pSceneManager;	//Delete instance
		pSceneManager = nullptr;//Set the pointer to nullptr
	}

}

void CSceneManager::RenderCurrent()
{
	Scenes[nCurrentScene]->render(); //Rending the current scene 

}

void CSceneManager::UpdateCurrent()
{
	Scenes[nCurrentScene]->update();

}

void CSceneManager::init()
{
	glutIgnoreKeyRepeat(1);
	ShaderLoader shaderloader;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	CUtility::program = shaderloader.CreateProgram("Shaders/VertexShader.txt", "Shaders/FragmentShader.txt");
	//---------------|Level Scenes Stuff|---------------//
	//Gets the initial values of the controls
	//creaing a shared pointer to level and bgSprite and CharacterSpr
	//Adding the spr to level
	shared_ptr<CLevel>Level = make_shared<CLevel>();
	Level->addLevelObj();
	Level->addPlayer();
	//Adding the level to scenemanager
	//---------------|Menu Scenes Stuff|---------------//
	//---------------|End Scenes Stuff|---------------//
	//Adding the scenes to scenemanager
	CSceneManager::GetInstance()->SceneAdd(Level);

}

void CSceneManager::switchScene(int nNewScene)
{
	nCurrentScene = nNewScene;
}

void CSceneManager::SceneAdd(std::shared_ptr<CScene> AddSc)
{
	Scenes.push_back(AddSc);
}

// Constructor //
CSceneManager::CSceneManager()
{

}

// Destructor //
CSceneManager::~CSceneManager()
{
	Scenes.clear();
}

