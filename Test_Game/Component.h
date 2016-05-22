#pragma once


enum ComponentType
{
	SPRITE,
	TRANSFORM,

	NUM_COMPONENTS
};

class Entity;

class Component
{
	public:

		Component(ComponentType type) { mType = type; }
		virtual ~Component() { };
		virtual void update() = 0;
		virtual Component *clone() = 0;
	
		ComponentType GetType() { return mType; }

		Entity *mOwner;
	
	private:
		ComponentType mType;
};

#include "Sprite.h"
#include "Transform.h"