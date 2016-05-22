#pragma once


enum ComponentType
{
	COMPONENT_SPRITE,
	COMPONENT_TRANSFORM,

	COMPONENT_NUM_COMPONENTS
};

class Entity;

class Component
{
	public:

		Component(ComponentType type) { mType = type; }
		virtual ~Component() { };
		virtual void update() = 0;      // used to update the logic of the component 

		virtual Component *clone() = 0; // used to get a copy of this component (includes owner pointer)
		/*
		This is an example of the clone function that each component should have
		(can be copied and "Sprite" replaced with the name of the component)

		Component *Sprite::clone()
		{
			return new Sprite(*this);
		}
		*/
	
		// returns the type of this component
		ComponentType GetType() { return mType; }

		// A pointer to the owner of this component.
		// This pointer is automatically set when the 
		//    Entity's addComponent Func is called
		Entity *mOwner;
	
	private:
		// the type of this component
		ComponentType mType;
};

#include "Sprite.h"
#include "Transform.h"