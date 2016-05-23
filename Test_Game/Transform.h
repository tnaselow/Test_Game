#pragma once

#include "Component.h"
#include "Zia\Math.h"

class Transform : public Component
{
	public:
		Transform() : Component(COMPONENT_TRANSFORM), mChanged(true) { };

		void update();
		Component *clone();

		Mat4 getModelMatrix() { return mModelMatrix; }

		void setPosition(Vec2 vec);
		void setScale(Vec2 vec);
		void setRotation(float rot);

		Vec2 getPosition() { return mPosition; }
		Vec2 getScale() { return mScale; }
		float getRotation() { return mRotation; }

	
	private:
		Vec2 mPosition;
		Vec2 mScale;
		float mRotation;

		Mat4 mModelMatrix;
		
		bool mChanged;
};