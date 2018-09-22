//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Time.cpp
// Description	:	main implementation for Time
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// This Include
#include "Time.h"

// Local Include
#include "Utility.h"

// Static Variable
CTime* CTime::s_pTime = nullptr;

CTime* CTime::GetInstance()
{
	if (s_pTime == nullptr)
	{
		s_pTime = new CTime();
	}
	
	return s_pTime;
}

void CTime::DestroyInstance()
{
	delete s_pTime;
	s_pTime = nullptr;
}

void CTime::Initialize()
{
	oldTime = (float)glutGet(GLUT_ELAPSED_TIME);
	TickTime = 0.01666666f;
	deltaTimeTick = 0.0f;
}

void CTime::Update()
{
	newTime = (float)glutGet(GLUT_ELAPSED_TIME);
	deltaTime = newTime - oldTime;

	oldTime = newTime;
	deltaTimeTick += deltaTime;
	if (deltaTimeTick >= TickTime)
	{
		deltaTimeTick = 0.0f;
	}
}

float CTime::GetDeltaTime() const
{
	return deltaTime;
}

float CTime::GetTick() const
{
	return deltaTimeTick;
}
