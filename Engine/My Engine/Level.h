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


	void ProcessMouse();
	void MouseDown(const b2Vec2& p);
	void MouseUp(const b2Vec2& p);
	void MouseMove(const b2Vec2& p);
	void Spring(const b2Vec2& p);
	void Box(const b2Vec2& p);


	b2MouseJoint* m_mouseJoint = NULL;
	b2Body* m_groundBody = NULL;
	
	//void delEnemy(std::shared_ptr<CEnemy>);
	//std::vector<std::shared_ptr<CEnemy>> v_Enemies;
private:
	//std::shared_ptr<CBird>Player;
	std::shared_ptr<CEntity>EndSpr;
	std::shared_ptr<CEntity>CircleofSling;
	int nScore = 0;
	float gravity = 9.81f;

	bool m_mousePressed;
	b2Vec2 m_mouseWorld;
	b2AABB m_worldAABB;

};

#endif // _CLEVEL_H__

