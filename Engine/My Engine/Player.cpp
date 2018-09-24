#include "Player.h"



CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

/***********************
* AddBird: Add bird to the player's list
* @author: Vivian Ngo
* @date: 24/09/18
* @parameter: _bird
***********************/
void CPlayer::AddBird(CBird _bird)
{

}

/***********************
* RemoveBird: Remove bird when player shoots bird
* @author: Vivian Ngo
* @date: 24/09/18
* @parameter: _bird
***********************/
void CPlayer::FlingBird()
{
	m_vBirdList.erase(m_vBirdList.begin());
}
