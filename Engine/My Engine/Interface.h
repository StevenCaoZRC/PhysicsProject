//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Interface.h
// Description	:	header file outlining the Interface
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

#ifndef _INTERFACE_H__
#define _INTERFACE_H__

// Library Includes //

// Local Includes //
#include "TextLabel.h"

// Types //

// Constants //

// Prototypes //
class TextLabel;
class CInterface
{
	// Member Functions //
public:
	static CInterface* GetInstance();
	static void DestroyInstance();
	void update();
	void render();
	bool bWon = false;
	TextLabel label;
	TextLabel WinText;
	TextLabel LostText;
private:
	CInterface();
	~CInterface();
	static CInterface* pInterface;
	CInterface(CInterface const&) = delete; //Deletes copy constructor
	void operator = (CInterface const&) = delete; //Deletes the operator assigned to the copy constructor
};

#endif // _CINTERFACE_H__

