//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Blocks.cpp
// Description	:	main implementation for Blocks
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

// This Includes //
#include "Enemy.h"

using namespace std;

// Constructor //
CEnemy::CEnemy()
{

}

// Destructor //
CEnemy::~CEnemy()
{

}

void CEnemy::CreateEntity2D(const char * _filePath, int iWidth, int iHeight)
{
	CEntity::CreateEntity2D(_filePath, iWidth, iHeight);
}

void CEnemy::Update2D()
{



}

