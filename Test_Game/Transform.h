#pragma once

#include "Component.h"
#include "Sapph\Matrix4.h"
#include "Sapph\Vector3.h"

class Transform : public Component
{
	public:
		Transform() : Component(TRANSFORM), mChanged(true) { };

		void update();
		Component *clone();

		Matrix4 getModelMatrix() { return mModelMatrix; }

		void setPosition(Vector3 vec);
		void setScale(Vector3 vec);
		void setRotation(float rot);

		Vector3 getPosition() { return mPosition; }
		Vector3 getScale() { return mScale; }
		float getRotation() { return mRotation; }

	
	private:
		Vector3 mPosition;
		Vector3 mScale;
		float mRotation;

		Matrix4 mModelMatrix;
		
		bool mChanged;
		
};