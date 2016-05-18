#pragma once

#include "Component.h"
#include "Sapph\Matrix4.h"
#include "Sapph\Vector3.h"

class Transform : public Component
{
	public:
		Transform() : Component(TRANSFORM), changed(true) { };

		void Update();

		Matrix4 GetModelMatrix() { return ModelMatrix; }

		void SetPosition(Vector3 vec);
		void SetScale(Vector3 vec);
		void SetRotation(float rot);

		Vector3 GetPosition() { return Position; }
		Vector3 GetScale() { return Scale; }
		float GetRotation() { return Rotation; }

	
	private:
		Vector3 Position;
		Vector3 Scale;
		float Rotation;

		Matrix4 ModelMatrix;
		
		bool changed;
		
};