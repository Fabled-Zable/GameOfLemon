#include <iostream>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Gamestates/Gamestate.h"
#include "Gamestates/TitleState.h"

class Engine : public olc::PixelGameEngine
{
public:

	CTitleState* titleState;

	CGamestate* currentState;

	Engine()
	{
		sAppName = "Game Of Lemon";
	}

	bool OnUserCreate() override
	{
		Clear(olc::BLANK);
		for (int i = 0; i < ELayers::End; i++) {
			EnableLayer(CreateLayer(),true);
		}

		this->titleState = new CTitleState(this);
		this->currentState = titleState;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		currentState->Update(fElapsedTime);
		return true;
	}
};

int main(std::string args)
{
	Engine engine;
	if (engine.Construct(1024, 720, 1, 1))
		engine.Start();

	return 0;
}