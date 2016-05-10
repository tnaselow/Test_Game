#pragma once
#include "GL\glew.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
	public:
		GameState	CurrentState;
		bool		Keys[1024];
		unsigned	Width, Height;

		Game(unsigned width, unsigned height);
		~Game();

		void ProccessInput(float dt);
		void Update(float dt);
		void Render();
};