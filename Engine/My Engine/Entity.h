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
	virtual void CreateEntity2D(const char * _filePath, int iWidth, int iHeight);
	virtual void Render2D(GLuint _programID);
	virtual void Update2D();
	int GetHeight() { return m_iHeight; };
	int GetWidth() { return m_iWidth; };
	int iTags;

	glm::vec3 objPosition = { 0.0,0.0,0.0 };
	glm::vec3 objRotate = { 0.0,0.0,0.0 };
	glm::vec3 objScale = { 1.0f,1.0f,1.0f };

	
	//Box2D Stuff
	b2Body* bodyb2d = nullptr;
	void CreateB2Body(b2World& b2dWorld, b2BodyType BodyType, bool bRotatable, bool bHasFixture, float fFriction, float fDensity, Utility::Shapes Shape);
protected:
		float m_fMass;
		float fGravity;
private:
	int m_iWidth;
	int m_iHeight;


	GLuint m_vao; // Vertex Array Obj
	GLuint m_vbo;
	GLuint m_tex; // Texture Obj	
	GLuint m_ebo;

};