#pragma once

#include "Component.h"
#include "Sapph\Vector3.h"
#include "Texture2D.h"


class Sprite : public Component
{
	public:
		Sprite() : Component(SPRITE), Color(1, 1, 1) {};

		void Draw();
		void Update() {};

		Texture2D Texture;
		Vector3 Color;
};