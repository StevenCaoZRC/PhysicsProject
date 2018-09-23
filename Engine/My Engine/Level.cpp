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
#include "Controls.h"
// This Includes //
#include "Level.h"

// Static Variables //

// Static Function Prototypes //

// Types //
using namespace std;

// Constructor //
CLevel::CLevel()
	:world(b2Vec2(0.0f, -10.0f))
{
	//world.SetGravity(b2Vec2(0.0f, -gravity));
}

// Destructor //
CLevel::~CLevel()
{

}

void CLevel::addPlayer()
{
	auto bird1 = std::make_shared<CBird>();
	bird1->InitBird(Utility::BIRD);
	bird1->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true);
	m_vBirdsInScene.push_back(bird1);

	auto bird2 = std::make_shared<CBird>();
	bird2->InitBird(Utility::FASTBIRD);
	bird2->SetPos({ 0.0f, 0.0f, 0.0f });
	bird2->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true);
	m_vBirdsInScene.push_back(bird2);
	////Creating Player
	//Player = make_shared<CPlayer>();
	//Player->CreateEntity2D("Resources/Aliens/alienPink_round.png", 80, 80);
	//Player->init2D({ {-6.75f,0.0f,0.0f} ,{0.0f,0.0f,0.0f} ,{ 1.0f,1.0f,1.0f } }, Utility::BIRD);
	//Player->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true);


	/*Player = make_shared<CBird>();
	Player->InitBird();
	Player->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true);

	AddEntity(Player);*/
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
	Background->init2D({ { 0.0f,-1.25f,0.0f },{0,0,0},{ 1.0f,1.5f,1.0f } }, Utility::BACKGROUND);

	std::shared_ptr<CEntity>Floor = make_shared<CEntity>();
	Floor->CreateEntity2D("Resources/other/floor.png", 1600, 80);
	Floor->init2D({ { 0.0f ,-5.125f,0.0f},{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, Utility::INDESOBJECTS);
	Floor->CreateB2Body(world, b2_staticBody, Utility::POLYGON, true, true);

	CircleofSling = make_shared<CEntity>();
	CircleofSling->CreateEntity2D("Resources/Stone elements/elementStone001.png", 100, 100);
	CircleofSling->init2D({ { -7.75f ,-2.8f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, Utility::INDESOBJECTS);
	CircleofSling->CreateB2Body(world, b2_staticBody, Utility::POLYGON, 1,false, true);

	std::shared_ptr<CEntity>StickofSling = make_shared<CEntity>();
	StickofSling->CreateEntity2D("Resources/Stone elements/elementStone017.png", 45, 140);
	StickofSling->init2D({ { -7.75f ,-4.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, Utility::INDESOBJECTS);
	StickofSling->CreateB2Body(world, b2_staticBody, Utility::POLYGON, false, true);
	AddEntity(Background);
	AddEntity(StickofSling);
	AddEntity(Floor);
	AddEntity(CircleofSling);
}

void CLevel::addText()
{
	auto xText = std::make_shared<TextLabel>("x: ", "Resources/Fonts/bubble.TTF", glm::vec2());
	auto yText = std::make_shared<TextLabel>("y: ", "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH / 2, 0.0f));
	//auto lives = std::make_shared<TextLabel>("Lives: ", "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH / 2, 0.0f));
	xText->SetScale(0.5f);
	yText->SetScale(0.5f);

	m_mTextList["MouseX"] = std::move(xText);
	m_mTextList["MouseY"] = std::move(yText);
}

void CLevel::render()
{
	CScene::render();

}

void CLevel::update()
{
	CScene::update();
	float32 timeStep = 1.0f / 120.0f;
	int32 velocityIteration = 6;
	int32 positionInteration = 2;
	world.Step(timeStep, velocityIteration, positionInteration);

	m_mTextList.find("MouseX")->second->SetText("x: " + std::to_string(CControls::m_fMouseX));
	m_mTextList.find("MouseY")->second->SetText("y: " + std::to_string(CControls::m_fMouseY));

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

