//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Entity.h
// Description	:	header file outlining the Entity
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//
#pragma once

// Global Include
#include "Utility.h"
#include "Camera.h"

class CEntity : public std::enable_shared_from_this<CEntity>//this allows me to return shared ptr form itself(using keyword THIS)
{
public:
	CEntity();
	~CEntity();
	virtual void init2D(Utility::Transform transform, Utility::Tags IDTags);
	void CreateEntity2D(const char * _filePath, int iWidth, int iHeight);
	virtual void Render2D(GLuint _programID);
	virtual void Update2D();
	int GetHeight() { return m_iHeight; };
	int GetWidth() { return m_iWidth; };


	glm::vec3 objPosition = { 0.0,0.0,0.0 };
	glm::vec3 objRotate = { 0.0,0.0,0.0 };
	glm::vec3 objScale = { 1.0f,1.0f,1.0f };

	//Setters and Getters
	void SetPos(glm::vec3 Movement) { objPosition = Movement; }
	void SetRotatation(glm::vec3 Rotation) { objRotate = Rotation; }
	void SetScale(glm::vec3 scale) { objScale = scale; }

	glm::vec3 GetPos() { return objPosition; }
	glm::vec3 GetRot() { return objRotate; }
	glm::vec3 GetScale() { return objScale; }
	
	Utility::Tags GetEntityType() { iTags; }
	const char* SelectSprite(Utility::Tags _tag);

	//heath for stuff
	int iHealth;
	//Box2D Stuff
	b2Body* bodyb2d = nullptr;

	b2Body* GetBody() { return bodyb2d; }
	void CreateB2Body(b2World& b2dWorld, b2BodyType BodyType, Utility::Shapes Shape, bool bRotatable = true, bool bHasFixture = true , float fDensity = 1.0f, float fFriction = 0.3f);
protected:
	float m_fMass;
	float fGravity;
private:
	int m_iWidth;
	int m_iHeight;
	Utility::Tags iTags;

	GLuint m_vao; // Vertex Array Obj
	GLuint m_vbo;
	GLuint m_tex; // Texture Obj	
	GLuint m_ebo;

};