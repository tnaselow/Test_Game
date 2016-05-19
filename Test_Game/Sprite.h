#pragma once

#include "Component.h"
#include "Sapph\Vector3.h"
#include "Texture2D.h"


class Sprite : public Component
{
	public:
		Sprite() : Component(SPRITE), mColor(1, 1, 1) {};

		void Draw();
		void Update() {};

		Component *clone();

		Texture2D mTexture;
		Vector3 mColor;
};