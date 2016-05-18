#pragma once

#include <vector>
#include "Component.h"


class Entity
{
	public:
		Entity();
		Entity(const Entity &entity);
		~Entity();

		void Update();
		void Draw();

		void operator=(const Entity &entity);
		Component *AddComponent(ComponentType type);
		
		template <typename T>
		T *AddComponent(ComponentType type) 
		{
			if (components[type] == nullptr)
			{
				components[type] = new T;	
				components[type]->Owner = this;
				return static_cast<T *>(components[type]);
			}
			else
				return nullptr;
		};

		template <typename T>
		T *GetComponent(ComponentType type) { return static_cast<T *>(components[type]); }

		Component *GetComponent(ComponentType type);


	private:
		std::vector<Component *> components;
};