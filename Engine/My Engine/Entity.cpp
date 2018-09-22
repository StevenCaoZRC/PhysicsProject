#include "Entity.h"

CEntity::CEntity()
{
}

CEntity::~CEntity()
{
}

void CEntity::init2D(Utility::Transform transform, Utility::Tags IDTags)
{
	iTags = IDTags;
	objPosition = transform.position;
	objRotate = transform.rotation;
	objScale = transform.scale;

}

void CEntity::CreateEntity2D(const char * _filePath, int iWidth, int iHeight)
{

	int HalfWidth = iWidth / 2;
	int HalfHeight =iHeight / 2;
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

	textureloader.TexImage2D(CEntity::m_iWidth, CEntity::m_iHeight, textureloader.imageloader(_filePath, CEntity::m_iWidth, CEntity::m_iHeight));

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
	glm::mat4 MVP = CCamera::GetInstance()->SetMVP2D({ objPosition, objRotate, objScale });				//CCamera::GetInstance()->GetMVP();
	GLint MVPLoc = glGetUniformLocation(_programID, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(MVP));

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void CEntity::Update2D()
{
}

void CEntity::CreateB2Body(b2World & b2dWorld, b2BodyType BodyType, bool bRotatable, bool bHasFixture, float fFriction, float fDensity, Utility::Shapes Shape)
{
	if (this)
	{
		b2BodyDef bodyDef;
		bodyDef.type = BodyType;
		bodyDef.position.Set(objPosition.x, objPosition.y);
		bodyDef.userData = &*this;
		bodyb2d = b2dWorld.CreateBody(&bodyDef);
		bodyb2d->SetTransform(bodyDef.position, (objRotate.z / 180) * b2_pi);
		bodyb2d->SetFixedRotation(!bRotatable);
		switch (Shape)
		{
		case 0:
		{
			b2PolygonShape b2DynamicShape;
			b2DynamicShape.SetAsBox((float)(m_iWidth / 2), (float)(m_iHeight / 2));
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
			break;
		}
		case 1:
		{
			b2CircleShape b2Circle;
			b2Circle.m_p.Set(0, 0);
			b2Circle.m_radius = (float)(m_iWidth / 2);
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
			break;
		}
		default:
			break;
		}
	}
}

