#pragma once

//Local Include 
#include "Utility.h"

class CCamera
{
public:
	//Projection Matrix 3D
	void SetProj3D(int iSCR_Width, int iSCR_Height);
	//Projection Matrix 2D
	void SetProj2D(int iSCR_Width, int iSCR_Height);
	glm::mat4 GetProj() { return m_m4Proj; };

	//View Matrix 2D
	void SetView2D();
	//View Matrix 3D
	void SetView3D(glm::mat4 View);
	glm::mat4 GetView() { return m_m4View; };

	//Model Matrix 2D
	void SetModel2D(Utility::Transform transform);
	//Model Matrix 3D
	void SetModel3D(glm::mat4 Model);
	glm::mat4 GetModel() { return m_m4Model; };

	//Gets Translation, Rotation and scale matrix
	glm::mat4 GetTranslation() { return m_m4Translate; };
	glm::mat4 GetRotation() { return m_m4Rotate; };
	glm::mat4 GetScale() { return m_m4Scale; };

	//MVP Matrix 2D
	glm::mat4 SetMVP2D(Utility::Transform transform);
	//MVP Matrix 3D
	void SetMVP3D();
	//GetMVP() { return m_m4MVP; };

private:
	//---------------| Matrices for MVP |---------------//
	glm::mat4 m_m4MVP;
	glm::mat4 m_m4Proj;
	glm::mat4 m_m4Model;
	glm::mat4 m_m4View;
	//---------------| Matrices for Model |-------------//
	glm::mat4 m_m4Scale;
	glm::mat4 m_m4Translate;
	glm::mat4 m_m4Rotate;
	//---------------| Camera Vectors |-----------------//
	glm::vec3 m_v3CamPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 m_v3CamForward = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 m_v3CamUp = glm::vec3(0.0f, 1.0f, 0.0f);

//Singleton
public:
	static CCamera* GetInstance();
	static void DestroyInstance();
private:
	static CCamera* m_pCamera;
	CCamera();
	~CCamera();
	CCamera(CCamera const&) = delete; //Deletes copy constructor
	void operator = (CCamera const&) = delete; //Deletes operator assigned to the copy constructor
};