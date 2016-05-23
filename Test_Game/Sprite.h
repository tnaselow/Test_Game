#pragma once

#include "Component.h"
#include "Texture2D.h"
#include "Zia\Math.h"


class Sprite : public Component
{
	public:
		Sprite() : Component(COMPONENT_SPRITE), mColor(1, 1, 1) {};

		void draw();
		void update() {};

		Component *clone();

		Texture2D mTexture;
		Vec3 mColor;
};