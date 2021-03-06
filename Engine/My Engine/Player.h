//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name	:	CPlayer.h
// Description	:	header file outlining the CPlayer
// Author		:	Steven Cao
// Mail			:	steven.zha7447@mediadesign.school.nz
//

#pragma once

#ifndef _CPLAYER_H__
#define _CPLAYER_H__

// Library Includes //

// Local Includes //
#include "Entity.h"
#include "Controls.h"
#include "Scene.h"
#include "Level.h"
#include "SceneManager.h"
//#include "CGameMech.h"
// Types //

// Constants //

// Prototypes //

class CPlayer : public CEntity
{

public:
	CPlayer();
	~CPlayer();
	void init2D(float _fMass, Utility::Transform transform, Utility::Tags IDTags);
	void CreateEntity2D(const char * _filePath, int iWidth, int iHeight);
	void update();
	bool bIsPlayerAlive = true;
private:

	glm::vec2 v2_Movement = glm::vec2();
};

#endif // _CPLAYER_H__

