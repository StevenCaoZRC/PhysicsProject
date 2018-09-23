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

void CBlocks::initBlock(Utility::Tags _tag, Utility::Transform transform, int _iHealth, int iWidth, int iHeight)
{
	iHealth = _iHealth;
	CreateEntity2D(SelectSprite(_tag), iWidth, iHeight);
	init2D(transform, _tag);
}

void CBlocks::Update2D()
{
	if (bodyb2d)
	{
		b2Vec2 BodyPosition = bodyb2d->GetPosition();
		objPosition = glm::vec3(BodyPosition.x, BodyPosition.y, 0.0f);
		objRotate.z = (bodyb2d->GetAngle() / b2_pi) * 180;
	}
	if (this->iHealth == 0)
	{
		CSceneManager::GetInstance()->GetCurrentScene()->DeleteEntity(this->shared_from_this());
	}
	//Case tag -> do action
}