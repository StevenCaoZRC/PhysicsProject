//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Controls.cpp
// Description	:	main implementation for Controls
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// Library Includes //

// Local Includes //

// This Includes //
#include "Controls.h"

// Types //
using namespace std;
//Redefining the static variable for class
CControls* CControls::m_pControls;
unsigned char CControls::cSpecKeyState[255];
unsigned char CControls::cMouse[3];
GLfloat CControls::MouseSensitivity = 0.05f;
GLfloat CControls::Yaw = 0.0f;
GLfloat CControls::Pitch = 0.0f;
GLfloat CControls::Roll = 0.0f;
GLfloat CControls::LastX = 0.0f;
GLfloat CControls::LastY = 0.0f;
GLfloat CControls::xOffset = 0.0f;
GLfloat CControls::yOffset = 0.0f;
bool CControls::FirstMouse = true;
float CControls::m_fMouseX = 0.0f;
float CControls::m_fMouseY = 0.0f;

CControls::CControls()
{
}

CControls::~CControls()
{
}

CControls * CControls::GetInstance()
{
	if (!m_pControls)
	{
		m_pControls = new CControls();//creates an instance of controls
	}
	return m_pControls;
}

void CControls::DestroyInstance()
{
	if (m_pControls) //Checks to see if instance exists
	{
		delete m_pControls; //deletes instance
		m_pControls = nullptr;//set the pointer to nullptr
	}
}

void CControls::init()
{
	//Sets the keyboard call back to current window
	glutKeyboardFunc(InitKeyDown);
	//Sets the keyboard on release call back to current window
	glutKeyboardUpFunc(InitKeyUp);

	glutSpecialFunc(SpecialKeyPress);
	glutSpecialUpFunc(SpecialKeyRelease);

	glutPassiveMotionFunc(MousePassiveMovement);
	glutMotionFunc(MouseHoldMovement);
	glutMouseFunc(Mouse);

}

void CControls::update()
{
	for (int i = 0; i < cKeyState[255]; i++)
	{
		if (cKeyState[i] == INPUT_FIRST_PRESSED)
		{
			cKeyState[i] = INPUT_HOLD;
		}
		else if (cKeyState[i] == INPUT_FIRST_RELEASE)
		{
			cKeyState[i] = INPUT_RELEASED;
		}

	}

}

void CControls::KeyDown(unsigned char cKey, int nX, int nY)
{
	cKeyState[cKey] = INPUT_FIRST_PRESSED;
}

void CControls::KeyUp(unsigned char cKey, int nX, int nY)
{
	cKeyState[cKey] = INPUT_FIRST_RELEASE;
}

void CControls::InitKeyUp(unsigned char cKey, int nX, int nY)
{
	CControls::GetInstance()->KeyUp(cKey, nX, nY);
}

void CControls::InitKeyDown(unsigned char cKey, int nX, int nY)
{
	CControls::GetInstance()->KeyDown(cKey, nX, nY);
}

void CControls::Mouse(int nButton, int nGlutState, int nX, int nY)
{
	if (nButton < 3)
	{
		//Checking and tracking the mousees current button state
		cMouse[nButton] = (nGlutState == GLUT_DOWN) ? INPUT_HOLD : INPUT_RELEASED;
	}
}

void CControls::MousePassiveMovement(int x, int y)
{
	m_fMouseX = (float)x;
	m_fMouseY = (float)y;
	if (FirstMouse == true)// Run only once to initialize the 'Last' vars
	{
		LastX = (GLfloat)x;
		LastY = (GLfloat)y;
		FirstMouse = false;
	}

	LastX = (GLfloat)x;
	LastY = (GLfloat)y;

	xOffset *= MouseSensitivity;
	yOffset *= MouseSensitivity;

	Yaw -= xOffset;
	Pitch -= yOffset;

	// Clamp 'Pitch' so screen doesn’t flip
	if (Pitch > 89.0f)
	{
		Pitch = 89.0f;
	}
	if (Pitch < -89.0f)
	{
		Pitch = -89.0f;
	}
}

void CControls::MouseHoldMovement(int x, int y)
{
	if (cMouse[0] == INPUT_HOLD)
	{
		if (FirstMouse == true)// Run only once to initialize the 'Last' vars
		{
			LastX = (GLfloat)x;
			LastY = (GLfloat)y;
			FirstMouse = false;
		}
		m_fMouseX = (float)x;
		m_fMouseY = (float)y;

		GLfloat xOffset = (GLfloat)x - LastX;
		GLfloat yOffset = (GLfloat)y - LastY;

		LastX = (GLfloat)x;
		LastY = (GLfloat)y;
		 
		xOffset *= MouseSensitivity + 0.05f;
		yOffset *= MouseSensitivity + 0.05f;

		Yaw -= xOffset;

		Pitch -= yOffset;

		if (Pitch > 89.0f)
		{
			Pitch = 89.0f;
		}
		if (Pitch < -89.0f)
		{
			Pitch = -89.0f;
		}
	}
}

void CControls::SpecialKeyPress(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		cSpecKeyState[0] = INPUT_HOLD;
		break;
	}
	case GLUT_KEY_DOWN:
	{
		cSpecKeyState[1] = INPUT_HOLD;
		break;
	}
	case GLUT_KEY_LEFT:
	{
		cSpecKeyState[2] = INPUT_HOLD;
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		cSpecKeyState[3] = INPUT_HOLD;
		break;
	}
	}
}

void CControls::SpecialKeyRelease(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		cSpecKeyState[0] = INPUT_RELEASED;
		break;
	}
	case GLUT_KEY_DOWN:
	{
		cSpecKeyState[1] = INPUT_RELEASED;
		break;

	}
	case GLUT_KEY_LEFT:
	{
		cSpecKeyState[2] = INPUT_RELEASED;
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		cSpecKeyState[3] = INPUT_RELEASED;
		break;
	}
	}
}
