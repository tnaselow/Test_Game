#pragma once
#include <vector>
#include "Entity.h"
#include "Renderer.h"

class Level
{
	public:
		std::vector<Entity> Bricks;

		Level () {};

		void Load(const char *file, unsigned lvlWidth, unsigned lvlHeight);

		void Draw(Renderer renderer);

		bool IsCompleted();
	private:

		void Init(const std::vector<std::vector<unsigned>> &tileData, unsigned lvlWidth, unsigned lvlHeight);
};