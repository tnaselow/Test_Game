//
// INSERT HEADER COMMENT HERE
//
#pragma once

#include <vector>
#include "Component.h"

class Entity
{
	public:
		Entity();
		Entity(const Entity &entity);
		~Entity();

		void update(); // calls update on all components
		void draw();   // if there is a sprite component attatched uses it to draw

		void operator=(const Entity &entity);
		

		/*************************************************************************
		* Brief: Used to add components to this entity
		*
		* param T    : The type (component inherited class) to use for this component.
		* param type : The type (ComponentType enum) of this component.
		*
		* return     : A pointer to the newely created Component
		**************************************************************************/
		template <typename T>
		T *AddComponent(ComponentType type) 
		{
			if (mComponents[type] == nullptr)
			{
				mComponents[type] = new T;
				mComponents[type]->mOwner = this;
				return static_cast<T *>(mComponents[type]);
			}
			else
				return nullptr;
		};

		/*************************************************************************
		* Brief: Used to get a pointer to a component of this entity
		*
		* param T    : The type (component inherited class) of the component.
		* param type : The type (ComponentType enum) of this component.
		*
		* return     : A pointer to the wanted Component
		**************************************************************************/
		template <typename T>
		T *GetComponent(ComponentType type) { return static_cast<T *>(mComponents[type]); }


	private:
		// A vector of all the components on this entity
		std::vector<Component *> mComponents;
};