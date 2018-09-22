//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Interface.cpp
// Description	:	main implementation for Interface
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// Local Includes //
#include "Controls.h"
#include "SceneManager.h"
#include "Level.h"
#include "TextLabel.h"
//#include "CEnemy.h"
// This Includes //
#include "Interface.h"


// Types //
using namespace std;
CInterface * CInterface::pInterface;
CInterface * CInterface::GetInstance()
{
	if (!pInterface) // If this does not exist
	{
		pInterface = new CInterface(); //Create an instance of interface
	}

	return pInterface;	//Returns the static instance
}

void CInterface::DestroyInstance()
{
	if (pInterface)//If the instance exists
	{
		delete pInterface;	//Delete instance
		pInterface = nullptr;//Set the pointer to nullptr
	}
}

void CInterface::update()
{
	
}

void CInterface::render()
{

}

// Constructor //
CInterface::CInterface()
	:label("Score: ", "Resources/fonts/waltographUI.ttf", glm::vec2(100.0f, 650.0f)), WinText("You Won!", "Resources/fonts/waltographUI.ttf", glm::vec2(Utility::SCR_WIDTH / 2.5, (Utility::SCR_HEIGHT / 2) + 100.0f)), LostText("You Lost!", "Resources/fonts/waltographUI.ttf", glm::vec2(Utility::SCR_WIDTH / 2.5, (Utility::SCR_HEIGHT / 2) + 100.0f))
{
	WinText.SetScale(1.0f);
	label.SetScale(1.0f);
	label.SetColor(glm::vec3(1.0f, 1.0f, 0.2f));
	WinText.SetColor(glm::vec3(0.0f, 1.0f, 0.0f));
	LostText.SetColor(glm::vec3(1.0f, 0.0f, 0.0f));
}

// Destructor //
CInterface::~CInterface()
{

}

