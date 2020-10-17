#pragma once
#include "Gamestate.h"
#include <math.h>

class CTitleState : public CGamestate
{
public:
	olc::Sprite* SText;
	olc::Decal* DText;

	float ticks = 0;

	CTitleState(olc::PixelGameEngine* e) : CGamestate(e)
	{
		SText = new olc::Sprite(e->ScreenWidth(), e->ScreenHeight());
		e->SetDrawTarget(SText);
		e->Clear(olc::BLANK);
		e->DrawString({ SText->width / 2 - (4 * 5 * 13), SText->height / 3 }, "GAME OF LEMON", olc::YELLOW,5);
		e->DrawString({ SText->width / 2 + (4 * 5 * 13) - (8 * 2 * 6), SText->height / 3 + 8*5 }, "-ZABLE", olc::YELLOW, 2);
		DText = new olc::Decal(SText);

		
	}

	void Update(float fElapsedTime) override
	{
		ticks += 0.01;
		e->SetDrawTarget(ELayers::TitleLayer);
		e->Clear(olc::VERY_DARK_YELLOW);
		e->DrawRotatedDecal({e->ScreenWidth()/2.0f,e->ScreenHeight() / 2.0f }, DText, sin(ticks) * 0.8f, { e->ScreenWidth() / 2.0f,e->ScreenHeight() / 2.0f });

	}
};