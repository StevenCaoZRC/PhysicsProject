//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Scene.h
// Description	:	header file outlining the Scene
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

// Library Includes //
#include <vector>
#include <memory>
// Local Includes //
#include "Entity.h"
#include "TextLabel.h"
#include "Bird.h"

class CContactListener : public b2ContactListener
{
public:
	CContactListener();
	~CContactListener();
	void BeginContact(b2Contact* contact);
};

//class CSprite; 
class CScene
{
public:
	CScene();
	~CScene();
	virtual void render();
	virtual void update();
	void DeleteEntity(std::shared_ptr<CEntity> TobeDeleted);
	void AddEntity(std::shared_ptr<CEntity> TobeAdded);
	std::shared_ptr<CEntity> GetEntity(Utility::Tags _tag);
	std::shared_ptr<CBird> GetCurrentBird();

	//vector of entites taht getscalled in render
	std::vector<std::shared_ptr<CBird>> m_vBirdsInScene;

	std::vector<std::shared_ptr<CEntity>> V_EntitiesInScene;
	std::map<std::string, std::shared_ptr<TextLabel>> m_mTextList;

	b2World world;
	CContactListener Listener;
	void DecreaseEnemyCount() { --enemyCount; }

	int GetEnemyCount() { return enemyCount; }

	void SetGameLost(bool _lost) { m_bGameLost = _lost; }
	bool GetGameLost() { return m_bGameLost; }

protected:
	int enemyCount = 0;
	bool m_bGameLost = false;

private: 
	int sceneNumber = 0;

};



