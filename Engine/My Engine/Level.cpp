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
#include "Time.h"

// Static Variables //

// Static Function Prototypes //

// Types //
using namespace std;

// Constructor //
CLevel::CLevel()
{
	b2BodyDef bodyDef;
	m_groundBody = world.CreateBody(&bodyDef);
}

CLevel::CLevel(int levelNum)
{
	m_iLevelNum = levelNum;
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
	bird1->SetPos({ -7.0f, 0.0f, 0.0f });
	bird1->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true, 0.4f);
	m_vBirdsInScene.push_back(bird1);

	auto bird2 = std::make_shared<CBird>();
	bird2->InitBird(Utility::FASTBIRD);
	bird2->SetPos({ -8.0f, -4.0f, 0.0f });
	bird2->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true, 0.4f);
	m_vBirdsInScene.push_back(bird2);

	auto bird3 = std::make_shared<CBird>();
	bird3->InitBird(Utility::BIGBIRD);
	bird3->SetPos({ -8.5f, -4.0f, 0.0f });
	bird3->CreateB2Body(world, b2_dynamicBody, Utility::CIRCLE, true, true, 1.0f);
	m_vBirdsInScene.push_back(bird3);
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
	CircleofSling->init2D({ { -7.0f ,-2.9f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, Utility::INDESOBJECTS);
	//CircleofSling->CreateB2Body(world, b2_kinematicBody, Utility::POLYGON ,false, false);

	m_circleSling = CircleofSling;

	std::shared_ptr<CEntity>StickofSling = make_shared<CEntity>();
	StickofSling->CreateEntity2D("Resources/Stone elements/elementStone017.png", 45, 125);
	StickofSling->init2D({ { -7.0f ,-4.18f,0.0f },{ 0,2.0,0 },{ 1.0f,1.0f,1.0f } }, Utility::INDESOBJECTS);
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

void CLevel::addLevel1Objects()
{
	auto LevelTitle = std::make_shared<TextLabel>("Level " + std::to_string(m_iLevelNum+1), "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH / 2 - 225.0f, Utility::SCR_HEIGHT / 2));

	LevelTitle->SetScale(2.0f);

	m_mTextList["Level"] = std::move(LevelTitle);
	//--------------------Adding Blocks to the Level--------------------//
	//std::shared_ptr<CBlocks> Block;
	addBlocks(Utility::WOODBOX, b2_dynamicBody, { { 7.5f ,-4.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::WOODBOX, b2_dynamicBody, { { 7.5f ,-3.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::WOODBOX, b2_dynamicBody, { { 7.5f ,-1.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::STONELONG, b2_staticBody, { { 5.5f ,3.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 120, 80);
	addBlocks(Utility::STONELONG, b2_dynamicBody, { { 5.5f ,1.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	//for rope to attach on to 
	addBlocks(Utility::STONEROUND, b2_dynamicBody, { { 7.5f ,3.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1);


	//WORLD BLOCKS that prevent birds from flying out of screen
	addBlocks(Utility::STONELONG, b2_staticBody, { { -10.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 80, 1000);
	addBlocks(Utility::STONELONG, b2_staticBody, { { 10.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 80, 1000);
	addBlocks(Utility::STONELONG, b2_staticBody, { { 10.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 80, 1000);
	addBlocks(Utility::STONELONG, b2_staticBody, { { 0.0f ,6.5f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 1600, 80);



	addEnemy(Utility::PIG, { { 7.5f , 0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addRevoluteJoint(*GetEntity(Utility::STONELONG)->GetBody(), *GetEntity(Utility::PIG)->GetBody());
	addWeldJoint(*GetEntity(Utility::STONEROUND)->GetBody(), *GetEntity(Utility::PIG)->GetBody());

}

void CLevel::addLevel2Objects()
{
	auto LevelTitle = std::make_shared<TextLabel>("Level " + std::to_string(m_iLevelNum+1), "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH / 2 - 225.0f, Utility::SCR_HEIGHT / 2));

	LevelTitle->SetScale(2.0f);

	m_mTextList["Level"] = std::move(LevelTitle);
	//--------------------Adding Blocks to the Level--------------------//
	//std::shared_ptr<CBlocks> Block;
	addBlocks(Utility::WOODBOX, b2_dynamicBody, { { 7.5f ,-4.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::WOODBOX, b2_dynamicBody, { { 3.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::WOODBOX, b2_dynamicBody, { { 3.5f ,-1.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addBlocks(Utility::STONELONG, b2_staticBody, { { 5.5f ,3.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 120, 80);
	addBlocks(Utility::STONELONG, b2_dynamicBody, { { 5.5f ,1.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	//for rope to attach on to 
	addBlocks(Utility::STONEROUND, b2_staticBody, { { -5.5f ,3.1f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });

	//WORLD BLOCKS that prevent birds from flying out of screen
	addBlocks(Utility::STONELONG, b2_staticBody, { { -10.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 80, 1000);
	addBlocks(Utility::STONELONG, b2_staticBody, { { 10.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 80, 1000);
	addBlocks(Utility::STONELONG, b2_staticBody, { { 10.5f ,0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 80, 1000);
	addBlocks(Utility::STONELONG, b2_staticBody, { { 0.0f ,6.5f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } }, 1, 1600, 80);

	addEnemy(Utility::PIG, { { 7.5f , 0.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
	addEnemy(Utility::PIG, { { 5.5f , 2.0f,0.0f },{ 0,0,0 },{ 1.0f,1.0f,1.0f } });
}

void CLevel::addMainMenu()
{
	auto GameTitle = std::make_shared<TextLabel>("GRUMPY BIRDS", "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH/2 - 225.0f, Utility::SCR_HEIGHT/2));
	auto Start = std::make_shared<TextLabel>("Click anywhere to start", "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH/2 - 200.0f, Utility::SCR_HEIGHT/2 - 100));
	auto GameStatus = std::make_shared<TextLabel>("", "Resources/Fonts/bubble.TTF", glm::vec2(Utility::SCR_WIDTH / 2 - 150.0f, Utility::SCR_HEIGHT / 2 - 200));

	GameTitle->SetColor({ 0.2f , 0.5f, 0.8f});
	GameTitle->SetScale(1.0f);
	Start->SetColor({ 0.2f , 0.5f, 0.8f });
	Start->SetScale(0.5f);
	GameStatus->SetColor({ 0.2f , 0.8f, 0.9f });
	GameStatus->SetScale(1.0f);

	m_mTextList["Title"] = std::move(GameTitle);
	m_mTextList["Start"] = std::move(Start);
	m_mTextList["Status"] = std::move(GameStatus);

}

void CLevel::addBlocks(Utility::Tags _tag, b2BodyType _type, Utility::Transform transform, int _Health, int iWidth, int iHeight)
{
	std::shared_ptr<CBlocks> Block = make_shared<CBlocks>();
	Block->initBlock(_tag, transform, _Health, iWidth, iHeight);
	Block->CreateB2Body(world, _type, Utility::POLYGON, true, true);
	AddEntity(Block);
}

void CLevel::addEnemy(Utility::Tags _tag, Utility::Transform transform, int _Health, int iWidth, int iHeight)
{
	std::shared_ptr<CEnemy> Enemy = make_shared<CEnemy>();
	Enemy->initEnemy(_tag, transform, _Health, iWidth, iHeight);
	Enemy->SetPos({ 7.75f, 0.0f, 0.0f });
	Enemy->CreateB2Body(world, b2_dynamicBody, Utility::POLYGON, true, true);
	++enemyCount;
	AddEntity(Enemy);
}

void CLevel::addDistanceJoint(b2Body & _body1, b2Body & _body2)
{
	b2DistanceJointDef distJointDef;

	distJointDef.bodyA = &_body1;
	distJointDef.bodyB = &_body2;
	distJointDef.length = 0.1f;
	distJointDef.frequencyHz = 3.0f;
	distJointDef.dampingRatio = 1.0f;
	distJointDef.Initialize(&_body1, &_body2, _body1.GetWorldCenter(), _body2.GetWorldCenter());
	distJointDef.collideConnected = false;
	m_pDistJoint = (b2DistanceJoint*) world.CreateJoint(&distJointDef);
}

void CLevel::addRevoluteJoint(b2Body & _body1, b2Body & _body2)
{
	b2RevoluteJointDef revoluteDef;

	revoluteDef.bodyA = &_body1;
	revoluteDef.bodyB = &_body2;
	revoluteDef.Initialize(&_body1, &_body2, _body1.GetWorldCenter());	
	revoluteDef.lowerAngle = -0.5f * b2_pi; // -90 degrees 
	revoluteDef.upperAngle = 0.25f * b2_pi; // 45 degrees 
	revoluteDef.enableLimit = true;
	revoluteDef.maxMotorTorque = 10.0f;
	revoluteDef.motorSpeed = 5.0f;
	revoluteDef.enableMotor = true;
	m_revoluteBod = (b2RevoluteJoint*)world.CreateJoint(&revoluteDef);
}

void CLevel::addRopeJoint(b2Body & _body1)
{

}

void CLevel::addWeldJoint(b2Body & _body1, b2Body & _body2)
{
	b2WeldJointDef weldDef;
	weldDef.bodyA = &_body1;
	weldDef.bodyB = &_body2;
	//weldDef.Initialize(&_body1, &_body2, _body2.GetWorldCenter());
	//weldDef.collideConnected = true;
	weldDef.localAnchorA = weldDef.bodyA->GetLocalPoint({ 0.0, 1.0f });
	weldDef.localAnchorB = weldDef.bodyB->GetLocalPoint({ 0.0, -1.0f });
	weldDef.dampingRatio = 6.0f;
	m_weld = (b2WeldJoint*)world.CreateJoint(&weldDef);
}

void CLevel::render()
{
	CScene::render();

}

void CLevel::update()
{
	CScene::update();
	float32 timeStep = CTime::GetInstance()->GetDeltaTime();//1.0f / 60.0f;
	int32 velocityIteration = 6;
	int32 positionInteration = 2;
	world.Step(timeStep, velocityIteration, positionInteration);

	if (m_iLevelNum == 2)
	{
		//If Main Menu
		//Handle one mouse click
		if (CControls::cMouse[0] == Utility::INPUT_HOLD)
		{
			m_bGameLost = true;
		}
	}
	else
	{
		//If not Main Menu
		m_mTextList.find("MouseX")->second->SetText("x: " + std::to_string(m_mouseWorld.x));
		m_mTextList.find("MouseY")->second->SetText("y: " + std::to_string(m_mouseWorld.y));
		ProcessMouse();
		m_pCurrentBird = GetCurrentBird();
		if (m_pCurrentBird != NULL)
		{
			if (!GetCurrentBird()->GetIsAlive())
			{
				world.DestroyBody(m_pCurrentBird->GetBody());
				DeleteEntity(m_pCurrentBird);
				if (m_vBirdsInScene.size() != 0)
				{
					GetCurrentBird()->GetBody()->SetTransform({ -7.0f, -3.0f }, 0.0f);
				}
				else
				{
					m_bGameLost = true;
				}
			}
		}
	}

	
	
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
	}
	else
	{
		if (m_mousePressed)
		{
			MouseUp(pw);
			m_mousePressed = false;
		}
	}
}

void CLevel::MouseDown(const b2Vec2& p)
{
	m_mouseWorld = p;
	m_mousePressed = true;
	if (m_pMouseJoint != NULL)
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
		m_currentBodyHeld = callback.m_fixture->GetBody();
		m_currentBodyHeld->GetUserData();
		b2MouseJointDef md;
		md.bodyA = m_groundBody;
		md.bodyB = m_currentBodyHeld;
		md.target = p;
		md.maxForce = 2.0f;// *m_currentBodyHeld->GetMass();
		md.dampingRatio = 4.0f;
		md.frequencyHz = 5.0f;
		m_pMouseJoint = (b2MouseJoint*)world.CreateJoint(&md);
		//m_currentBodyHeld->IsFixedRotation();
		m_currentBodyHeld->SetAwake(true);
		
		/*if (!m_bJointConnected)
			addDistanceJoint(*m_pCurrentBird, *m_circleSling);*/
		m_bJointConnected = true;
	}
	
}

void CLevel::MouseUp(const b2Vec2& p)
{
	if (m_pMouseJoint!= NULL)
	{
		float32 strength = m_pMouseJoint->GetMaxForce();
		world.DestroyJoint(m_pMouseJoint);
		m_mousePressed = false;
		std::cout << "MouseJoint Destroyed" << std::endl;
		m_pMouseJoint = NULL;
		
		if (m_pCurrentBird!=NULL)
		{
			if (!m_pCurrentBird->GetIsFlung())
			{
				float32 vecX = (CircleofSling->GetPos().x - p.x) * 5.0f;
				float32 vecY = (CircleofSling->GetPos().y - p.y) * 5.0f;

				float32 tempvecX = (m_pCurrentBird->GetBody()->GetWorldCenter().x - p.x); // *strength;
				float32 tempvecY = (m_pCurrentBird->GetBody()->GetWorldCenter().y - p.y);// * strength;
				std::cout << tempvecX << "," << tempvecY << std::endl;

				m_pCurrentBird->GetBody()->ApplyLinearImpulse({ vecX,vecY }, m_currentBodyHeld->GetWorldCenter(), true);
				m_pCurrentBird->SetFlung(true);

			}
		}
		
		//if (m_bJointConnected)
		//{
		//	m_bJointConnected = false;
		//	world.DestroyJoint(m_pDistJoint);
		//	std::cout << "DistJoint Destroyed" << std::endl;
		//	//m_pCurrentBird->ApplyLinearImpulseToCenter(b2Vec2(10, 0), true);
		//}
		
	}
}

void CLevel::MouseMove(const b2Vec2 & p)
{
	m_mouseWorld = p;
	m_groundBody->SetTransform(p, 0.0f);

	if (m_pMouseJoint && m_mousePressed)
	{
		//m_pMouseJoint->SetTarget(p);
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
			if (Bird && (Entity2->GetEntityType() != Utility::BIRD || Entity2->GetEntityType() != Utility::FASTBIRD))
			{
				cout << "BirdCollided" << endl;
			}
			else if (Pig && Entity2->GetEntityType() != Utility::PIG)
			{
				Pig->iHealth-=1;
				cout << "PigCollided" << endl;
			}
			else if (Block &&( Entity2->GetEntityType() != Utility::WOODBOX && Entity2->GetEntityType() != Utility::PIG) || Entity1->GetEntityType() == Utility::BIRD || Entity1->GetEntityType() == Utility::FASTBIRD || Entity1->GetEntityType() == Utility::BIGBIRD)
			{
				Block->iHealth--;
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
			if (Bird && (Entity1->GetEntityType() != Utility::BIRD || Entity1->GetEntityType() != Utility::FASTBIRD))
			{
				cout << "BirdCollided" << endl;
			}
			else if (Pig && Entity1->GetEntityType() != Utility::PIG)
			{
				Pig->iHealth--;
				cout << "PigCollided" << endl;
			}
			else if (Block && (Entity1->GetEntityType() != Utility::WOODBOX && Entity1->GetEntityType() != Utility::PIG)|| Entity1->GetEntityType() == Utility::BIRD || Entity1->GetEntityType() == Utility::FASTBIRD || Entity1->GetEntityType() == Utility::BIGBIRD)
			{
				Block->iHealth--;
				cout << "BlockCollided" << endl;
			}
		}
	}

}
