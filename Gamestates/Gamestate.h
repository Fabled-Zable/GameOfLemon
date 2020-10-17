#pragma once
#include "olcPixelGameEngine.h"

enum ELayers
{
	unused = 0,
	TitleLayer = 1,
	End,
};

class CGamestate
{
public:
	olc::PixelGameEngine* e;

	CGamestate(olc::PixelGameEngine* e)
	{
		this->e = e;
	}

	virtual void Update(float fElapsedTime) {}

};