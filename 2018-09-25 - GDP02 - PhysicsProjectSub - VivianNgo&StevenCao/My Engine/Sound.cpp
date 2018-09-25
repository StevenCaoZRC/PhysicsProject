//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Sound.cpp
// Description	:	main implementation for Sound
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// This Includes //
#include "Sound.h"

// Types //
using namespace std;

CSound * CSound::pSound;
CSound * CSound::GetInstance()
{
	if (!pSound)
	{
		pSound = new CSound();
	}
	return pSound;
}

void CSound::DestroyInstance()
{
	if (pSound)//If the Instance exists
	{
		delete pSound; //Deletes instance
		pSound = nullptr; //Set the pointer to nullptr
	}
}

bool CSound::init()
{
	FMOD_RESULT result;
	result = FMOD::System_Create(&soundMgr);
	if (result != FMOD_OK)
		return false;

	result = soundMgr->init(50, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK)
		return false;
	return true;
}

const bool CSound::addSound()
{
	FMOD_RESULT result;
	result = soundMgr->createSound("Resources/sound/Background.mp3", FMOD_DEFAULT, 0, &bgMusic);
	result = soundMgr->createSound("Resources/sound/Thump.wav", FMOD_DEFAULT, 0, &sfx);
	bgMusic->setMode(FMOD_LOOP_NORMAL);
	return true;
}

// Constructor //
CSound::CSound()
{

}

// Destructor //
CSound::~CSound()
{

}

