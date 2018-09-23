//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Entity.cpp
// Description	:	main implementation for Entity
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//
#include "Entity.h"

CEntity::CEntity()
{
}

CEntity::~CEntity()
{
}

void CEntity::init2D(Utility::Transform transform, Utility::Tags IDTags)
{
	// Determines what type of object it is. Either bird, pig, destructable objects, indestructable objects and background
	iTags = IDTags;
	//Sets the transform of the Entity
	objPosition = transform.position;
	objRotate = transform.rotation;
	objScale = transform.scale;

}

void CEntity::CreateEntity2D(const char * _filePath, int iWidth, int iHeight)
{
	m_iHeight = iHeight;
	m_iWidth = iWidth;
	int HalfWidth = iWidth / 2;
	int HalfHeight = iHeight / 2;
	//if the passed in height and width is zero then it will get the images height and width
	if (iWidth == 0 || iHeight == 0)
	{
		int nWidth, nHeight;
		unsigned char* image = SOIL_load_image(
			_filePath,				//File path/name
			&nWidth,							//Output for the image width
			&nHeight,						//Output for the image height
			0,								//Output for number of channels
			SOIL_LOAD_RGBA);
		SOIL_free_image_data(image);

		HalfWidth = nWidth;
		HalfHeight = nHeight;
	}
	GLfloat vertices[36] = {
		// Position			 //Colour			 //Tex Coords
		-HalfWidth, HalfHeight, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f,  // Top Left 
		HalfWidth, HalfHeight, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,  // Top Right 
		HalfWidth, -HalfHeight, 0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 1.0f,  // Bottom Right 
		-HalfWidth, -HalfHeight, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 1.0f,  // Bottom Left
	};
	GLuint indices[6] =
	{
		0, 1, 2, // First Triangle 
		0, 2, 3  // Second Triangle

	};
	TextureLoader textureloader;
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(vertices),
		vertices,
		GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,						// Layout location on vertex shader
		3,						// 3 float components (eg position)
		GL_FLOAT,				// Type of data
		GL_FALSE,				// Data Normalised?
		8 * sizeof(GLfloat),	// Stride of the entire single vertex
		(GLvoid*)0);			// Offset

	glEnableVertexAttribArray(0);

	// New AttribPointer for Colour
	glVertexAttribPointer(
		1,									// Layout location on vertex shader
		3,									// 3 float components (eg position)
		GL_FLOAT,							// Type of data
		GL_FALSE,							// Data Normalised?
		8 * sizeof(GLfloat),				// Stride of the entire single vertex
		(GLvoid*)(3 * sizeof(GLfloat)));		// Offset
	glEnableVertexAttribArray(1);

	// EBO
	glGenBuffers(1, &m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(indices),
		indices,
		GL_STATIC_DRAW);

	glCullFace(GL_BACK); //Cull the back faces (basicly deletes the faces that are going in CCW)
	glFrontFace(GL_CW);  //Front face is Clockwise order
						 //glEnable(GL_CULL_FACE);


	glGenTextures(1, &m_tex);
	glBindTexture(GL_TEXTURE_2D, m_tex);
	//Texture class to load images.
	//textures.push_back(m_tex);

	textureloader.TexImage2D(iWidth, iHeight, textureloader.imageloader(_filePath, iWidth, iHeight));

	//Text Coord attribute pointer
	glVertexAttribPointer(
		2,			//Layout location on vertex shader
		2,			//2 float components for texture coords
		GL_FLOAT,    //Type of data
		GL_FALSE,   //Data normalised?
		8 * sizeof(GLfloat),		//Stride
		(GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
}

void CEntity::Render2D(GLuint _programID)
{
	glUseProgram(_programID);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Activating the texture and binding it
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_tex);
	glUniform1i(glGetUniformLocation(_programID, "tex"), 0);

	glBindVertexArray(m_vao);			  // Bind VAO
	 //------3D MVP------//
	glm::mat4 MVP = CCamera::GetInstance()->SetMVP2D({ (objPosition * (float)Utility::PIXELUNIT), objRotate, objScale });				//CCamera::GetInstance()->GetMVP();
	GLint MVPLoc = glGetUniformLocation(_programID, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(MVP));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void CEntity::Update2D()
{
	
	
}

void CEntity::CreateB2Body(b2World& b2dWorld, b2BodyType BodyType, Utility::Shapes Shape, bool bRotatable, bool bHasFixture, float fDensity, float fFriction)
{
	//Creating a body definition
	b2BodyDef bodyDef;
	//Define which body type, Dynamic, Static or Kinematic
	bodyDef.type = BodyType;
	//Sets the position of the body to the same position as the game entity 
	bodyDef.position.Set(objPosition.x, objPosition.y);
	//Box2D version of a pointer, which points from a physics object to a game entity
	bodyDef.userData = &*this;
	//Create body
	bodyb2d = b2dWorld.CreateBody(&bodyDef);
	//Set the transform of the physics object according to the transform of the game entity
	bodyb2d->SetTransform(bodyDef.position, (objRotate.z / 180) * b2_pi);
	//Only sets fix rotation if the passed in value is false(therefore cannot rotate)
	bodyb2d->SetFixedRotation(!bRotatable);
	//Decides to the shape

	switch (Shape)
	{
	case Utility::POLYGON:
	{
		b2PolygonShape b2DynamicShape;
		
		b2DynamicShape.SetAsBox((GetWidth() /2.0f / Utility::PIXELUNIT), (GetHeight() /2.0f / Utility::PIXELUNIT));
		if (bHasFixture)
		{
			//Define fixture
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &b2DynamicShape;
			//Setting the density
			fixtureDef.density = fDensity;
			//Setting the friction
			fixtureDef.friction = fFriction;
			//add this fixture to the body
			bodyb2d->CreateFixture(&fixtureDef);
		}
		else
		{
			bodyb2d->CreateFixture(&b2DynamicShape, 0.0f);
		}
		break;
	}
	case Utility::CIRCLE:
	{
		b2CircleShape b2Circle;
		b2Circle.m_p.Set(0.0f,0.0f);
		b2Circle.m_radius = (GetWidth()/ 2.0f / Utility::PIXELUNIT);// / Utility::PIXELUNIT);
		if (bHasFixture)
		{
			//Define fixture
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &b2Circle;
			//Setting the density
			fixtureDef.density = fDensity;
			//Setting the friction
			fixtureDef.friction = fFriction;
			//add this fixture to the body
			bodyb2d->CreateFixture(&fixtureDef);
		}
		else
		{
			bodyb2d->CreateFixture(&b2Circle, 0.0f);
		}
		break;
	}
	default:
	{break; }

	}
}

const char* CEntity::SelectSprite(Utility::Tags _tag)
{

	if (_tag == Utility::BIRD)
	{
		return SPR_BIRD;
	}
	else if (_tag == Utility::FASTBIRD)
	{
		return SPR_FASTBIRD;
	}
	else if (_tag == Utility::TRIPLEBIRD)
	{
		return SPR_TRIBIRD;
	}
	else if (_tag == Utility::WOODBOX)
	{
		return SPR_WOODBOX;
	}
	else if (_tag == Utility::PIG)
	{
		return SPR_PIG;
	}
	return SPR_WOODBOX; //default
}

