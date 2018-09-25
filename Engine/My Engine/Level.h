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
	void addBlocks(Utility::Tags _tag, b2BodyType _type, Utility::Transform transform, int _Health = 1 , int iWidth = 80, int iHeight = 80);
	void addEnemy(Utility::Tags _tag, Utility::Transform transform, int _Health = 1, int iWidth = 80, int iHeight = 80);
	void addDistanceJoint(b2Body& _body1, b2Body& _body2);
	void addRevoluteJoint(b2Body& _body1, b2Body& _body2);
	void addWeldJoint(b2Body& _body1, b2Body& _body2);
	void render();
	void update();
	void resetLevel();


	void ProcessMouse();
	void MouseDown(const b2Vec2& p);
	void MouseUp(const b2Vec2& p);
	void MouseMove(const b2Vec2& p);

	
	//void delEnemy(std::shared_ptr<CEnemy>);
	//std::vector<std::shared_ptr<CEnemy>> v_Enemies;
private:
	//std::shared_ptr<CBird>Player;
	std::shared_ptr<CEntity>EndSpr;
	std::shared_ptr<CEntity>CircleofSling;
	int nScore = 0;
	float gravity = 9.81f;

	bool m_bJointConnected = false;
	bool m_mousePressed = false;
	b2Vec2 m_mouseWorld;
	b2MouseJoint* m_pMouseJoint = NULL;
	b2Body* m_groundBody = NULL;
	b2Body* m_currentBodyHeld = NULL;
	b2Body* m_circleSling = NULL;
	b2Body* m_pCurrentBird = NULL;
	b2RevoluteJoint* m_revoluteBod = NULL;
	b2WeldJoint* m_weld = nullptr;
	b2DistanceJoint* m_pDistJoint;
	b2RevoluteJoint* m_ropeRevo;
	float m_fOldTime = 0.0f;
	//float m_fOldTime;

};

#endif // _CLEVEL_H__

