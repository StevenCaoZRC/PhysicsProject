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
#include "Player.h"

using namespace std;

// Constructor //
CPlayer::CPlayer()
{

}

// Destructor //
CPlayer::~CPlayer()
{

}

void CPlayer::init2D(float _fMass, Utility::Transform transform, Utility::Tags IDTags)
{
	//Sets the stats of the player such has its starting position
	objPosition = transform.position;
	objScale = transform.scale;
	objRotate = transform.rotation;
	m_fMass = _fMass;
	//fGravity = 0.5f;

	//---------------|Sound Stuff|---------------//
	//CSound::GetInstance()->init();
	//CSound::GetInstance()->addSound();
	//CSound::GetInstance()->soundMgr->playSound(CSound::GetInstance()->bgMusic, 0, false, &CSound::GetInstance()->BgMusicChannel); \
	//	CSound::GetInstance()->soundEffects->setVolume(0.1f);
}

void CPlayer::CreateEntity2D(const char * _filePath, int iWidth, int iHeight)
{
	CEntity::CreateEntity2D(_filePath, iWidth, iHeight);
}

void CPlayer::Update2D()
{
	if (bodyb2d)
	{
		b2Vec2 BodyPosition = bodyb2d->GetPosition();
		objPosition = glm::vec3(BodyPosition.x, BodyPosition.y, 0.0f);
		objRotate.z = (bodyb2d->GetAngle() / b2_pi) * 180;
	}
	cout << objPosition.y << endl;
	////Casting current level scene to dirived type CLevel, if it is not Clevel will return nullptr
	//std::shared_ptr<CLevel>RefrenceLevel = std::dynamic_pointer_cast<CLevel>(CSceneManager::GetInstance()->GetCurrentScene());
	//if (!RefrenceLevel)
	//{
	//	return; //if the scene is not a level
	//}
	//if (CControls::GetInstance()->cKeyState[(unsigned char)'w'] == CControls::INPUT_FIRST_PRESSED && objPosition.y <= -215.0f)
	//{
	//	v2_Movement.y = fJumpHeight;
	//	iCurrentFrame = 1;
	//}
	//else
	//{
	//	if (objPosition.y - fGravity < -215.0f)
	//	{
	//		v2_Movement.y = 0;
	//		objPosition.y = -215.0f;
	//		iCurrentFrame = 0;

	//	}
	//	else if (objPosition.y != -215.0f)
	//	{
	//		v2_Movement.y -= fGravity;
	//	}
	//}

	//if (CControls::GetInstance()->cKeyState[(unsigned char)'d'] == CControls::INPUT_HOLD)
	//{
	//	if (objPosition.x + fMovementSpeed > Utility::SCR_WIDTH / 2 - 150.0f)
	//	{
	//		objPosition.x = Utility::SCR_WIDTH / 2 - 150.0f;
	//		v2_Movement.x = 0;
	//	}
	//	else
	//	{
	//		v2_Movement.x = fMovementSpeed;
	//	}
	//	objScale.x = 1;
	//}
	//else if (CControls::GetInstance()->cKeyState[(unsigned char)'a'] == CControls::INPUT_HOLD)
	//{
	//	if (objPosition.x - fMovementSpeed < -((float)Utility::SCR_WIDTH / 2) + 150.0f)
	//	{
	//		objPosition.x = -((float)Utility::SCR_WIDTH / 2) + 150.0f;
	//		v2_Movement.x = 0;
	//	}
	//	else
	//	{
	//		v2_Movement.x = -fMovementSpeed;
	//	}
	//	objScale.x = -1;
	//}
	//else
	//{
	//	v2_Movement.x = 0;
	//}
	//for (auto it : RefrenceLevel->v_Enemies) //Refrence level is current level
	//{
	//	if (CGameMech::bIsDetectingCollision(this->shared_from_this(), it, v2_Movement))
	//	{
	//		if (this->shared_from_this()->objPosition.x + this->shared_from_this()->nWidth + v2_Movement.x > it->objPosition.x &&
	//			this->shared_from_this()->objPosition.x + v2_Movement.x < it->objPosition.x + it->nWidth)
	//		{
	//			it->bIsAlive = false;
	//			RefrenceLevel->delEnemy(it);
	//			CSound::GetInstance()->soundMgr->playSound(CSound::GetInstance()->sfx, 0, false, &CSound::GetInstance()->soundEffects);
	//			CSound::GetInstance()->soundEffects->setVolume(0.6f);
	//			RefrenceLevel->nScore += 10;
	//			CInterface::CInterface::GetInstance()->bWon = true;

	//			return;
	//		}

	//		bIsPlayerAlive = false;
	//		CSound::GetInstance()->soundMgr->playSound(CSound::GetInstance()->sfx, 0, false, &CSound::GetInstance()->soundEffects);
	//		CSound::GetInstance()->soundEffects->setVolume(0.6f);
	//		RefrenceLevel->DeleteSprite(this->shared_from_this());
	//		if (CSceneManager::GetInstance()->nCurrentScene = CSceneManager::LEVEL && bIsPlayerAlive == false)
	//		{
	//			RefrenceLevel->delEnemy(it);
	//			RefrenceLevel->DeleteSprite(RefrenceLevel->CharacterSpr);
	//			RefrenceLevel->addEnemy();
	//			RefrenceLevel->addPlayer();
	//			RefrenceLevel->nScore = 0;
	//			CSceneManager::GetInstance()->nCurrentScene = CSceneManager::END;
	//			CInterface::CInterface::GetInstance()->bWon = false;

	//		}

	//	}

	//}
	////CSound::GetInstance()->soundMgr->playSound(CSound::GetInstance()->bgMusic, 0, false, &CSound::GetInstance()->BgMusicChannel);


	//objPosition += glm::vec3(v2_Movement, 0);\
	


}

