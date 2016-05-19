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

		Component(ComponentType type) { Type = type; }
		virtual ~Component() { };
		virtual void Update() = 0;
		virtual Component *clone() = 0;
	
		ComponentType GetType() { return Type; }

		Entity *Owner;
	
	private:
		ComponentType Type;
};

#include "Sprite.h"
#include "Transform.h"