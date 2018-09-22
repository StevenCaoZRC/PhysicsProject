//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name	:	CInterface.cpp
// Description	:	main implementation for CInterface
// Author		:	Steven Cao
// Mail 		:	steven.zha7447@mediadesign.school.nz
//

// Library Includes //

// Local Includes //
//#include "CControls.h"
//#include "CSceneManager.h"
//#include "CLevel.h"
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

