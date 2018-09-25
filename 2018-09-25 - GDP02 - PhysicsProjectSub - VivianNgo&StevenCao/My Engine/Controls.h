//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Controls.h
// Description	:	header file outlining the Controls
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//
#pragma once
//Library Includes
#include "Utility.h"
//Global Variable

class CControls
{
public:
	enum KeyState
	{
		INPUT_FIRST_RELEASE,	//First frame of Up state
		INPUT_RELEASED,			//Default State (Up)
		INPUT_FIRST_PRESSED,    //First frame of Down state
		INPUT_HOLD,				//Key is helped down
	};
	enum Mouse
	{
		MOUSE_LEFT,			//0
		MOUSE_MIDDLE,		//1
		MOUSE_RIGHT,		//2
	};
	static CControls* GetInstance();
	static void DestroyInstance();

	unsigned char cKeyState[255];
	static unsigned char cSpecKeyState[255];
	static unsigned char cMouse[3];

	static float m_fMouseX;
	static float m_fMouseY;

	void init();
	void update();
	static void InitKeyDown(unsigned char cKey, int nX, int nY);
	static void InitKeyUp(unsigned char cKey, int nX, int nY);
	void KeyDown(unsigned char cKey, int nX, int nY);
	void KeyUp(unsigned char cKey, int nX, int nY);
	static void SpecialKeyPress(int key, int x, int y);
	static void SpecialKeyRelease(int key, int x, int y);

	static void Mouse(int nButton, int nGlutState, int nX, int nY);
	static void MousePassiveMovement(int x, int y);
	static void MouseHoldMovement(int x, int y);

private:
	CControls();
	~CControls();
	static CControls* m_pControls;
	CControls(CControls const&) = delete;//Deletes copy constructor
	void operator = (CControls const&) = delete;//Deletes the operator assgined to the copy constructor

	static GLfloat MouseSensitivity;
	static GLfloat Yaw;
	static GLfloat Pitch;
	static GLfloat Roll;
	static GLfloat LastX;
	static GLfloat LastY;
	static GLfloat xOffset;
	static GLfloat yOffset;
	static bool FirstMouse;
};