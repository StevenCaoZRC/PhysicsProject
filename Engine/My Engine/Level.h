#pragma once
//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name	:	CLevel.h
// Description	:	header file outlining the CLevel
// Author		:	Steven Cao
// Mail			:	steven.zha7447@mediadesign.school.nz
//

#pragma once

#ifndef _CLEVEL_H__
#define _CLEVEL_H__

// Library Includes //
#include "Utility.h"
// Local Includes //
#include "Scene.h"
#include"TextLabel.h"
#include "Player.h"
// Types //

// Constants //

// Prototypes //
class CEnemy;
class CPlayer;
class CEntity;
class TextLabel;
class CLevel : public CScene
{
	// Member Functions //
public:
	CLevel();
	~CLevel();
	void addPlayer();
	void addEnemy();
	void addLevelObj();
	void render();
	void update();
	void resetLevel();
	//void delEnemy(std::shared_ptr<CEnemy>);
	//std::vector<std::shared_ptr<CEnemy>> v_Enemies;
private:
	std::shared_ptr<CPlayer>Player;
	std::shared_ptr<CEntity>EndSpr;
	std::shared_ptr<CEntity>CircleofSling;
	int nScore = 0;
	b2World
};

#endif // _CLEVEL_H__

