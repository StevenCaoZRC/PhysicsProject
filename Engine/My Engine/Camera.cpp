#include "Camera.h"

CCamera* CCamera::m_pCamera;

void CCamera::SetProj3D(int iSCR_Width, int iSCR_Height)
{
	m_m4Proj = glm::perspective(45.0f, (float)iSCR_Width / (float)iSCR_Height, 0.1f, 2000.0f);
}

void CCamera::SetProj2D(int iSCR_Width, int iSCR_Height)
{
	float fHalfScrWidth = (float)iSCR_Width / 80;
	float fHalfScrHeight = (float)iSCR_Height / 80;

	m_m4Proj = glm::ortho(-fHalfScrWidth, fHalfScrWidth, -fHalfScrHeight, fHalfScrHeight, 0.1f, 100.0f);
}

void CCamera::SetView2D()
{
	m_m4View = glm::lookAt(m_v3CamPos, m_v3CamPos + m_v3CamForward, m_v3CamUp);
}

glm::mat4 CCamera::SetMVP2D(Utility::Transform transform)
{
	SetView2D();
	SetProj2D(Utility::SCR_WIDTH, Utility::SCR_HEIGHT);
	m_m4Translate = glm::translate(glm::mat4(), transform.position);
	m_m4Scale = glm::scale(glm::mat4(), transform.scale);
	m_m4Rotate = glm::rotate(glm::mat4(), glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_m4Rotate = glm::rotate(glm::mat4(), glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_m4Rotate = glm::rotate(glm::mat4(), glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));


	//Model Matrix 2D
	m_m4Model = m_m4Translate * m_m4Rotate *m_m4Scale;
	m_m4MVP = m_m4Proj * m_m4View * m_m4Model;
	return m_m4MVP;
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
