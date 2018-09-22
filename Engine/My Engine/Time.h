//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2018 Media Design School
//
// File Name	:	Time.h
// Description	:	header file outlining the Time
// Author		:	Steven Cao & Vivian Ngo
// Mail 		:	steven.zha7447@mediadesign.school.nz, vivian.ngo7572@mediadesign.school.nz
//

#pragma once

class CTime
{

#pragma region Singleton

public:
	static CTime* GetInstance();
	static void DestroyInstance();

private:
	CTime() {}
	~CTime() {}

	// Non-copyable
	CTime(const CTime& _kr) = delete;
	CTime& operator= (const CTime& _kr) = delete;

protected:
	// Singleton Instance
	static CTime* s_pTime;

#pragma endregion Singleton

private:

	float deltaTime;
	float oldTime, newTime;
	float deltaTimeTick;
	float TickTime;
public:

	void Initialize();
	void Update();

	float GetDeltaTime() const;
	float GetTick() const;

};