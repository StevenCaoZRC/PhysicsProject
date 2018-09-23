//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Player.cpp
// Description	:	main implementation for Player
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// Local Includes //
#include "Interface.h"
#include "Sound.h"
// This Includes //
#include "Bird.h"

using namespace std;

// Constructor //
CBird::CBird()
{

}

// Destructor //
CBird::~CBird()
{
	
}

void CBird::InitBird(Utility::Tags _type)
{
	CreateEntity2D(SelectSprite(_type), 80, 80);
	init2D({ { -6.75f,0.0f,0.0f } ,{ 0.0f,0.0f,0.0f } ,{ 1.0f,1.0f,1.0f } }, _type);
}

void CBird::Update2D()
{
	if (bodyb2d)
	{
		b2Vec2 BodyPosition = bodyb2d->GetPosition();
		objPosition = glm::vec3(BodyPosition.x, BodyPosition.y, 0.0f);
		objRotate.z = (bodyb2d->GetAngle() / b2_pi) * 180;
	}
}

const char* CBird::SelectSprite(Utility::Tags _tag)
{
	if (_tag == Utility::BIRD)
	{
		return SPR_BIRD;
	}
	else if (_tag == Utility::FASTBIRD)
	{
		return SPR_FASTBIRD;
	}
	else if (_tag == Utility::TRIPLEBIRD)
	{
		return SPR_TRIBIRD;
	}
}

