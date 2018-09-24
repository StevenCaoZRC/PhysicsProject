#pragma once

#include "Bird.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	int GetBirdsLeft() { return m_vBirdList.size(); }

	void AddBird(CBird _bird);
	void FlingBird();

private:
	//int m_iLives; 
	std::vector < std::shared_ptr<CBird>> m_vBirdList;
};

