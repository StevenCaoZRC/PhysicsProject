//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	ContactListener.h
// Description	:	header file outlining the ContactListener
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once
#include "Utility.h"

class CContactListener : public b2ContactListener
{
public:
	CContactListener();
	~CContactListener();
	void BeginContact(b2Contact* contact);
};