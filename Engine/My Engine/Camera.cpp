//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Camera.cpp
// Description	:	main implementation for Camera
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//
#include "Camera.h"
#include "Controls.h"


CCamera* CCamera::m_pCamera;

void CCamera::SetProj3D(int iSCR_Width, int iSCR_Height)
{
	//Sets the projection matrix to be persepctive
	m_m4Proj = glm::perspective(45.0f, (float)iSCR_Width / (float)iSCR_Height, 0.1f, 2000.0f);
}

void CCamera::SetProj2D(int iSCR_Width, int iSCR_Height)
{
	float fHalfScrWidth = (float)iSCR_Width / 2.0f;
	float fHalfScrHeight = (float)iSCR_Height / 2.0f;
	//Sets the projection matrix to be orthographic 
	m_m4Proj = glm::ortho(-fHalfScrWidth, fHalfScrWidth, -fHalfScrHeight, fHalfScrHeight, 0.1f, 1000.0f);
}

void CCamera::SetView2D()
{
	//Sets where the camera should be looking
	m_m4View = glm::lookAt(m_v3CamPos, m_v3CamPos + m_v3CamForward, m_v3CamUp);
}

glm::mat4 CCamera::SetMVP2D(Utility::Transform transform)
{
	CameraMovement();
	SetView2D(); //Calls the set view func
	SetProj2D(Utility::SCR_WIDTH, Utility::SCR_HEIGHT); //Calls the set proj func
	//Sets the translation matrix to the passed in position
	m_m4Translate = glm::translate(glm::mat4(), transform.position);
	//Sets the Scale matrix equal to the scale passed in 
	m_m4Scale = glm::scale(glm::mat4(), transform.scale);
	//Sets the Rotation matrix equal to the passed in rotation values (values passed in is in degrees, so it is then converted to radians)
	m_m4Rotate = glm::rotate(glm::mat4(), glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_m4Rotate = glm::rotate(glm::mat4(), glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_m4Rotate = glm::rotate(glm::mat4(), glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));


	//Model Matrix 2D
	//Calculates the model matrix
	m_m4Model = m_m4Translate * m_m4Rotate *m_m4Scale;
	//Calculates the MVP matrix
	m_m4MVP = m_m4Proj * m_m4View * m_m4Model;
	return m_m4MVP;
}

void CCamera::CameraMovement()
{
	float cameraSpeed = 0.05f;
	if (CControls::GetInstance()->cSpecKeyState[0] == Utility::INPUT_HOLD)
	{
		m_v3CamPos.y += cameraSpeed; //+= cameraSpeed * cameraUp;
	}
	else if (CControls::GetInstance()->cSpecKeyState[1] == Utility::INPUT_HOLD)
	{
		m_v3CamPos.y -= +cameraSpeed; //-= cameraSpeed * cameraUp;
	}
	else if (CControls::GetInstance()->cSpecKeyState[2] == Utility::INPUT_HOLD)
	{
		m_v3CamPos.x -= cameraSpeed; //-= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
	else if (CControls::GetInstance()->cSpecKeyState[3] == Utility::INPUT_HOLD)
	{
		m_v3CamPos.x += cameraSpeed; //glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	}
}

CCamera * CCamera::GetInstance()
{
	if (!m_pCamera) //if camera pointer doesnt exist
	{
		m_pCamera = new CCamera(); //Create an instance of Camera
	}
	return m_pCamera;

}

void CCamera::DestroyInstance()
{
	if (m_pCamera) //If a camera instance exists
	{
		delete m_pCamera; //Deletes pointer
		m_pCamera = nullptr;//Gets pointer to nullptr
	}
}

//Constructor
CCamera::CCamera()
{
}

//Destructor
CCamera::~CCamera()
{
}
