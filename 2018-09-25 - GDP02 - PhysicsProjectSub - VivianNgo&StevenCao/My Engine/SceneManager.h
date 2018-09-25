//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	SceneManager.cpp
// Description	:	header file outlining the SceneManager
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef _CSCENEMANAGER_H__
#define _CSCENEMANAGER_H__

// Library Includes //
#include <vector>
#include <memory>
// Local Includes //
#include "Camera.h"
#include "Utility.h"
#include "Scene.h"
#include "Controls.h"

// Types //

// Constants //

// Prototypes //

class CSceneManager
{
	// Member Functions //
public:
	enum DiffScenes
	{
		MENU, //0
		LEVEL,//1
		END,  //2
	};
	static CSceneManager* GetInstance();
	static void DestroyInstance();
	void RenderCurrent();
	void UpdateCurrent();
	void ResetScenes();

	void init();
	void switchScene(int nNewScene);
	void SceneAdd(std::shared_ptr<CScene>AddSc); //Adds current scene to vector
	std::shared_ptr<CScene> GetCurrentScene() { return Scenes[nCurrentScene]; }; //Gets the current scene from the scene vector
	std::vector < std::shared_ptr<CScene> >Scenes;
	int nCurrentScene = 0;
private:
	CSceneManager();
	~CSceneManager();
	static CSceneManager* pSceneManager;
	CSceneManager(CSceneManager const&) = delete; //Deletes copy constructor
	void operator = (CSceneManager const&) = delete; //Deletes the operator assigned to the copy constructor

};

#endif // _CSCENEMANAGER_H__

