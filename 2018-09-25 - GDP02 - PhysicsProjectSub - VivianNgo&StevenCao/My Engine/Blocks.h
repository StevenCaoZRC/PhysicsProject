//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Blocks.h
// Description	:	header file outlining the Player
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef _CBLOCK_H__
#define _CBLOCK_H__

// Library Includes //

// Local Includes //
#include "Entity.h"
#include "Scene.h"
#include "Level.h"
#include "Utility.h"

class CBlocks : public CEntity
{

public:
	CBlocks();
	~CBlocks();
	void initBlock(Utility::Tags _tag, Utility::Transform transform, int _Health, int iWidth, int iHeight);
	void Update2D();

};

#endif // _CBLOCK_H__

