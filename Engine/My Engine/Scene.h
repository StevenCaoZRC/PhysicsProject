//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name	:	CScene.h
// Description	:	header file outlining the CScene
// Author		:	Steven Cao
// Mail			:	steven.zha7447@mediadesign.school.nz
//

#pragma once

// Library Includes //
#include <vector>
#include <memory>
// Local Includes //
#include "Entity.h"
//class CSprite; 
class CScene
{
public:
	CScene();
	~CScene();
	virtual void render();
	virtual void update();
	void DeleteEntity(std::shared_ptr<CEntity> TobeDeleted);
	void AddEntity(std::shared_ptr<CEntity> TobeAdded);
	//vector of entites taht getscalled in render
	std::vector<std::shared_ptr<CEntity>> V_EntitiesInScene;
};



