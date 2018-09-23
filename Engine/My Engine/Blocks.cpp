//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Blocks.cpp
// Description	:	main implementation for Blocks
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// This Includes //
#include "Blocks.h"

using namespace std;

// Constructor //
CBlocks::CBlocks()
{

}

// Destructor //
CBlocks::~CBlocks()
{

}

void CBlocks::initBlocks(b2World world, int _iHealth)
{
	
	iHealth = _iHealth;
}

void CBlocks::CreateEntity2D(const char * _filePath, int iWidth, int iHeight)
{
	CEntity::CreateEntity2D(_filePath, iWidth, iHeight);
}

void CBlocks::Update2D()
{
	if (bodyb2d)
	{
		b2Vec2 BodyPosition = bodyb2d->GetPosition();
		objPosition = glm::vec3(BodyPosition.x, BodyPosition.y, 0.0f);
		objRotate.z = (bodyb2d->GetAngle() / b2_pi) * 180;
	}


}

