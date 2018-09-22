//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Level.cpp
// Description	:	main implementation for Level
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//
// Library Includes //
#include <vector>
// Local Includes //
#include "Interface.h"
#include "TextLabel.h"
// This Includes //
#include "Level.h"

// Static Variables //

// Static Function Prototypes //

// Types //
using namespace std;

// Constructor //
CLevel::CLevel()
	:world(b2Vec2(0.0f, -9.81f))
{
	world.SetGravity(b2Vec2(0.0f, -gravity));
}

// Destructor //
CLevel::~CLevel()
{

}

void CLevel::addPlayer()
{
	float StartWidth = CircleofSling->GetWidth() / 2.0f;
	float StartHeight = CircleofSling->GetHeight() / 2.0f; 
	//Creating Player
	Player = make_shared<CPlayer>();
	Player->CreateEntity2D("Resources/Aliens/alienPink_round.png", 0.0f, 0.0f);
	Player->init2D(2.0f, { {-8,-5.5,1.0f} ,{0.0f,0.0f,0.0f} ,{ 0.01f,0.01f,0.01f } }, Utility::BIRD);
	Player->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true, 0.3f, 100.0f);
	//CharacterSpr->addFrame("Resources/player_character/character_jump_0.png");
	AddEntity(Player);
}

void CLevel::addEnemy()
{
	////Creating Enemy1
	//std::shared_ptr<CEnemy>SlimeSpr = make_shared<CEnemy>("Resources/enemies/slime0.png", 0.0f, 0.0f);
	//SlimeSpr->init(2.0f, 2.0f);
	//SlimeSpr->objPosition = { 0.0f,-224.0f,0.0f };
	//SpritesAdd(SlimeSpr);
	//v_Enemies.push_back(SlimeSpr);
}

void CLevel::addLevelObj()
{
	std::shared_ptr<CEntity>Background = make_shared<CEntity>();
	Background->CreateEntity2D("Resources/Backgrounds/blue_grass.png",Utility::SCR_WIDTH, Utility::SCR_HEIGHT);
	Background->init2D({ { 0.0f,-2.0f,0.0f },{0,0,0},{ 0.025f,0.035f,0.025f } }, Utility::BACKGROUND);
	std::shared_ptr<CEntity>Floor = make_shared<CEntity>();
	Floor->CreateEntity2D("Resources/other/floor.png", 0, 0);
	Floor->init2D({ { 0 ,-10.0f,0.0f },{ 0,0,0 },{ 0.02f,0.02f,0.02f } }, Utility::INDESOJBECTS);
	Floor->CreateB2Body(world, b2_staticBody, Utility::POLYGON, false, false);

	CircleofSling = make_shared<CEntity>();
	CircleofSling->CreateEntity2D("Resources/Stone elements/elementStone001.png", 0, 0);
	CircleofSling->init2D({ { -8 ,-5.5f,0.0f },{ 0,0,0 },{ 0.0135f,0.0135f,0.0135f } }, Utility::INDESOJBECTS);
	CircleofSling->CreateB2Body(world, b2_staticBody, Utility::POLYGON, false, false);

	std::shared_ptr<CEntity>StickofSling = make_shared<CEntity>();
	StickofSling->CreateEntity2D("Resources/Stone elements/elementStone017.png", 0, 0);
	StickofSling->init2D({ { -8 ,-7.5f,0.0f },{ 0,0,0 },{ 0.005f,0.01f,0.01f } }, Utility::INDESOJBECTS);
	StickofSling->CreateB2Body(world, b2_staticBody, Utility::POLYGON, false, false);
	AddEntity(Background);
	AddEntity(StickofSling);
	AddEntity(Floor);
	AddEntity(CircleofSling);
}

void CLevel::render()
{
	CScene::render();

}

void CLevel::update()
{
	CScene::update();
}

void CLevel::resetLevel()
{
	//if (!v_Enemies.empty())
	//{
	//	for (auto it : v_Enemies)
	//	{
	//		delEnemy(it);
	//	}

	//}
	//addEnemy();
	//DeleteEntity(Player);
	addPlayer();
	nScore = 0;

}

//void CLevel::delEnemy(std::shared_ptr<CEnemy>TobeDeleted)
//{
//	for (auto it = v_Enemies.begin(); it != v_Enemies.end(); it++)
//	{
//		if ((*it) == TobeDeleted)
//		{
//			v_Enemies.erase(it);
//			DeleteEntity(TobeDeleted);
//			break;
//		}
//
//	}
//}

