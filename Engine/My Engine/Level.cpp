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
{
	//world.SetGravity(b2Vec2(0.0f, -gravity));
	
	b2BodyDef bodyDef;
	m_groundBody = world.CreateBody(&bodyDef);
}

// Destructor //
CLevel::~CLevel()
{

}

void CLevel::addPlayer()
{
	auto bird1 = std::make_shared<CBird>();
	bird1->InitBird(Utility::BIRD);
	bird1->SetPos({ 0.0f, 0.0f, 0.0f });
	bird1->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true);
	m_vBirdsInScene.push_back(bird1);

	auto bird2 = std::make_shared<CBird>();
	bird2->InitBird(Utility::FASTBIRD);
	bird2->SetPos({ 0.0f, 0.0f, 0.0f });
	bird2->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true);
	m_vBirdsInScene.push_back(bird2);
}

void CLevel::addEnemy()
{

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
	//CircleofSling->CreateB2Body(world, b2_staticBody, Utility::POLYGON, 1,false, true);

	std::shared_ptr<CEntity>StickofSling = make_shared<CEntity>();
	StickofSling->CreateEntity2D("Resources/Stone elements/elementStone017.png", 45, 125);
	StickofSling->init2D({ { -7.75f ,-4.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, Utility::INDESOBJECTS);
	StickofSling->CreateB2Body(world, b2_staticBody, Utility::POLYGON, false, true);
	AddEntity(Background);
	AddEntity(StickofSling);
	AddEntity(Floor);
	AddEntity(CircleofSling);

	//--------------------Adding Blocks to the Level--------------------//
	//std::shared_ptr<CBlocks> Block;
	addBlocks(Utility::WOODBOX, { { 7.5f ,-4.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::WOODBOX, { { 7.5f ,-3.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::WOODBOX, { { 7.5f ,-1.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addEnemy(Utility::PIG, { { 7.5f , 0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
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

void CLevel::addBlocks(Utility::Tags _tag, Utility::Transform transform, int _Health, int iWidth, int iHeight)
{
	std::shared_ptr<CBlocks> Block = make_shared<CBlocks>();
	Block->initBlock(_tag, transform, _Health, iWidth, iHeight);
	Block->CreateB2Body(world, b2_dynamicBody, Utility::POLYGON, true, true);
	AddEntity(Block);
}

void CLevel::addEnemy(Utility::Tags _tag, Utility::Transform transform, int _Health, int iWidth, int iHeight)
{
	std::shared_ptr<CEnemy> Enemy = make_shared<CEnemy>();
	Enemy->initEnemy(_tag, transform, _Health, iWidth, iHeight);
	Enemy->SetPos({ 0.0f, 0.0f, 0.0f });
	Enemy->CreateB2Body(world, b2_dynamicBody, Utility::POLYGON, true, true);
	AddEntity(Enemy);
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

	b2Vec2 ps((float32)CControls::m_fMouseX, (float32)CControls::m_fMouseY);
	b2Vec2 pw = CCamera::GetInstance()->ConvertScreenToWorld(ps);

	m_mTextList.find("MouseX")->second->SetText("x: " + std::to_string(pw.x));
	m_mTextList.find("MouseY")->second->SetText("y: " + std::to_string(pw.y));
	ProcessMouse();
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

class QueryCallback : public b2QueryCallback
{
public:
	QueryCallback(const b2Vec2& point)
	{
		m_point = point;
		m_fixture = NULL;
	}

	bool ReportFixture(b2Fixture* fixture) override
	{
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody)
		{
			bool inside = fixture->TestPoint(m_point);
			if (inside)
			{
				m_fixture = fixture;

				// We are done, terminate the query.
				return false;
			}
		}

		// Continue the query.
		return true;
	}

	b2Vec2 m_point;
	b2Fixture* m_fixture;
};

void CLevel::ProcessMouse()
{

	b2Vec2 ps((float32)CControls::m_fMouseX, (float32)CControls::m_fMouseY);
	b2Vec2 pw = CCamera::GetInstance()->ConvertScreenToWorld(ps);

	MouseMove(pw);

	// Use the mouse to move things around.
	if (CControls::cMouse[0] == Utility::INPUT_HOLD)
	{
		MouseDown(pw);
		m_mousePressed = true;
		std::cout << "x: " << pw.x << "y: " << pw.y << std::endl;
	}
	else
	{
		if (m_mousePressed)
		{
			MouseUp(pw);
			std::cout << "released" << std::endl;
			m_mousePressed = false;
		}
	}
}

void CLevel::MouseDown(const b2Vec2& p)
{
	m_mouseWorld = p;

	if (m_mouseJoint != NULL)
	{
		return;
	}

	// Make a small box.
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.001f, 0.001f);
	aabb.lowerBound = p - d;
	aabb.upperBound = p + d;

	// Query the world for overlapping shapes.
	QueryCallback callback(p);
	world.QueryAABB(&callback, aabb);

	if (callback.m_fixture)
	{
		b2Body* body = callback.m_fixture->GetBody();
		b2MouseJointDef md;
		md.bodyA = m_groundBody;
		md.bodyB = body;
		md.target = p;
		md.maxForce = 1000.0f * body->GetMass();
		m_mouseJoint = (b2MouseJoint*)world.CreateJoint(&md);
		body->SetAwake(true);
	}
}

void CLevel::MouseUp(const b2Vec2& p)
{
	if (m_mouseJoint!= NULL)
	{
		world.DestroyJoint(m_mouseJoint);
		std::cout << "JointDestroyed" << std::endl;

		m_mouseJoint = NULL;
	}
}

void CLevel::MouseMove(const b2Vec2 & p)
{
	m_mouseWorld = p;
	m_groundBody->SetTransform(p, 0.0f);

	if (m_mouseJoint && m_mousePressed)
	{
		m_mouseJoint->SetTarget(p);
	}
}

CContactListener::CContactListener()
{
}

CContactListener::~CContactListener()
{
}

void CContactListener::BeginContact(b2Contact * contact)
{
	CEntity* Entity1 = static_cast<CEntity*>(contact->GetFixtureA()->GetBody()->GetUserData());
	CEntity* Entity2 = static_cast<CEntity*>(contact->GetFixtureB()->GetBody()->GetUserData());
	
	if (Entity1)
	{
		CBird* Bird = dynamic_cast<CBird*>(Entity1);
		CEnemy* Pig = dynamic_cast<CEnemy*>(Entity1);
		CBlocks* Block = dynamic_cast<CBlocks*>(Entity1);
		if (Entity1 != Entity2 )
		{
			if (Bird)
			{
				cout << "BirdCollided" << endl;
			}
			else if (Pig)
			{
				Pig->iHealth -= 1;
				cout << "PigCollided" << endl;
			}
			else if (Block)
			{
				Block->iHealth -= 1;
				cout << "BlockCollided" << endl;
			}
		}
		
	}
	if (Entity2)
	{
		CBird* Bird = dynamic_cast<CBird*>(Entity1);
		CEnemy* Pig = dynamic_cast<CEnemy*>(Entity1);
		CBlocks* Block = dynamic_cast<CBlocks*>(Entity1);
		if (Entity1 != Entity2 )//|| Entity1 != Entity1)
		{
			if (Bird)
			{
				cout << "BirdCollided" << endl;
			}
			else if (Pig)
			{
				Pig->iHealth -= 1;
				cout << "PigCollided" << endl;
			}
			else if (Block)
			{
				Block->iHealth -= 1;
				cout << "BlockCollided" << endl;
			}
		}
	}

}
