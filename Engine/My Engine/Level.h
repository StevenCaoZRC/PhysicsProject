//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Level.h
// Description	:	header file outlining the Level
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef _CLEVEL_H__
#define _CLEVEL_H__

// Library Includes //
#include "Utility.h"
// Local Includes //
#include "Scene.h"
#include "Bird.h"

//#include"TextLabel.h"
#include"TextLabel.h"
#include "Enemy.h"
#include "Blocks.h"
// Types //

// Constants //

// Prototypes //
//class CScene;
//class CEnemy;
//class CBird;
//class CFastBird;
//class CEntity;
class CContactListener : public b2ContactListener
{
public:
	CContactListener();
	~CContactListener();
	void BeginContact(b2Contact* contact);
};
class CLevel : public CScene
{
	// Member Functions //
public:
	CLevel();
	~CLevel();
	void addPlayer();
	void addEnemy();
	void addLevelObj();
	void addText();
	void addBlocks(Utility::Tags _tag, Utility::Transform transform, int _Health = 2 , int iWidth = 80, int iHeight = 80);
	void addEnemy(Utility::Tags _tag, Utility::Transform transform, int _Health = 2, int iWidth = 80, int iHeight = 80);

	void render();
	void update();
	void resetLevel();

	b2World world;

	//void delEnemy(std::shared_ptr<CEnemy>);
	//std::vector<std::shared_ptr<CEnemy>> v_Enemies;
private:
	//std::shared_ptr<CBird>Player;
	std::shared_ptr<CEntity>EndSpr;
	std::shared_ptr<CEntity>CircleofSling;
	int nScore = 0;
	float gravity = 9.81f;
	CContactListener ContactListener;
};



#endif // _CLEVEL_H__

