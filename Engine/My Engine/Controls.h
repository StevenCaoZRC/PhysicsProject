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
	unsigned char cMouse[3];
	void init();
	void update();
	static void InitKeyDown(unsigned char cKey, int nX, int nY);
	static void InitKeyUp(unsigned char cKey, int nX, int nY);
	void KeyDown(unsigned char cKey, int nX, int nY);
	void KeyUp(unsigned char cKey, int nX, int nY);


	void Mouse(int nButton, int nGlutState, int nX, int nY);


private:
	CControls();
	~CControls();
	static CControls* m_pControls;
	CControls(CControls const&) = delete;//Deletes copy constructor
	void operator = (CControls const&) = delete;//Deletes the operator assgined to the copy constructor
};