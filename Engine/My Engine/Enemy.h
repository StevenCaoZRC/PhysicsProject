//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Enemy.h
// Description	:	header file outlining the Player
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef _ENEMY_H__
#define _ENEMY_H__

// Library Includes //

// Local Includes //
#include "Entity.h"
#include "Scene.h"
#include "Level.h"
#include "SceneManager.h"

class CEnemy : public CEntity
{

public:
	CEnemy();
	~CEnemy();
	void initEnemy(Utility::Tags _tag, Utility::Transform transform, int _Health, int iWidth, int iHeight);
	void Update2D();

};

#endif // _ENEMY_H__


