#pragma once

//---OpenGL Includes---//
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include "glew.h"
#include "freeglut.h"
#include "SOIL.h"
#include "FMOD\fmod.hpp"
#include <Box2D.h>

//---Loaders---//
#include "TextureLoader.h"
#include "ShaderLoader.h"

//---Local Includes---//

//---Library Includes---//
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <Windows.h>
#include <thread>
#include <memory>
#include <cmath>
#include <vld.h>		// Memory Leak Detector

class CUtility
{
public:
	CUtility();
	~CUtility();

	static GLuint program;
};

namespace Utility
{
	const unsigned int SCR_WIDTH = 1000;
	const unsigned int SCR_HEIGHT = 850;

	enum Shapes
	{
		POLYGON = 0,
		CIRCLE,
	};

	enum InputState
	{
		INPUT_FIRST_RELEASE,	// First frame of Up state 
		INPUT_RELEASED,			// Default State (Up) 
		INPUT_FIRST_PRESS,		// First frame of Down state 
		INPUT_HOLD,				// Key is held Down 
	};

	enum InputMouse
	{
		MOUSE_LEFT,
		MOUSE_MIDDLE,
		MOUSE_RIGHT
	};

	struct Transform
	{
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
	};

	enum Tags
	{
		BIRD = 0,
		PIGS,
		DESOBJECTS,
		INDESOJBECTS,
		BACKGROUND,
	};

}

