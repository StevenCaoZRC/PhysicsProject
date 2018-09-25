#include "Clock.h"

Clock* Clock::s_pClockInstance = 0;
float Clock::m_fOldTime = 0;

/***********************
* GetInstance: Gets the instance of the clock singleton class
* @author: Vivian Ngo
* @date: 08/05/18
* @return: s_pClockInstance - Instance of the clock singleton class
***********************/
Clock* Clock::GetInstance()
{
	if (s_pClockInstance == 0)
	{
		s_pClockInstance = new Clock();
	}
	return s_pClockInstance;
}

/***********************
* DestroyInstance: Destroys the instance of the clock singleton class if there is one
* @author: Vivian Ngo
* @date: 08/05/18
***********************/
void Clock::DestroyInstance()
{
	if (s_pClockInstance != 0) // If there is an instance of this class
	{
		//Delete the instance
		delete s_pClockInstance;
		s_pClockInstance = nullptr;
	}
}

/***********************
* GetDeltaTime: Gets the delta time of the program
* @author: Vivian Ngo
* @date: 08/05/18
* @return: delta time of the program
***********************/
float Clock::GetDeltaTime()
{
	float currentTime = static_cast<float>(glutGet(GLUT_ELAPSED_TIME) / 1000.0f);
	float deltaTick = currentTime - m_fOldTime;
	m_fOldTime = currentTime; //Set new old time
	return deltaTick;
}