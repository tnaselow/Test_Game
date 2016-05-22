#pragma once

#include "Component.h"
#include "Sapph\Vector3.h"
#include "Texture2D.h"


class Sprite : public Component
{
	public:
		Sprite() : Component(COMPONENT_SPRITE), mColor(1, 1, 1) {};

		void draw();
		void update() {};

		Component *clone();

		Texture2D mTexture;
		Vector3 mColor;
};