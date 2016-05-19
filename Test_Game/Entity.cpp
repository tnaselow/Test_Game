#include "Entity.h"


Entity::Entity() : components(NUM_COMPONENTS)
{
	for (unsigned i = 0; i < components.size(); i++)
		components[i] = nullptr;
}

Entity::Entity(const Entity &entity) : components(NUM_COMPONENTS)
{
	for (unsigned i = 0; i < components.size(); i++)
		components[i] = nullptr;
	*this = entity;
}

Entity::~Entity()
{
	for (unsigned i = 0; i < components.size(); i++)
		if (components[i] != nullptr)
		{
			delete components[i];
			components[i] = nullptr;
		}
}

void Entity::operator=(const Entity &entity)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (entity.components[i] != nullptr)
		{
			components[i] = entity.components[i]->clone();
			components[i]->Owner = this;
		}
	}
}

void Entity::Update()
{
	for (unsigned i = 0; i < components.size(); i++)
		if (components[i] != nullptr)
			components[i]->Update();
}

void Entity::Draw()
{
	if (components[SPRITE] != nullptr)
	{
		Sprite *sprite = static_cast<Sprite *>(components[SPRITE]);
		sprite->Draw();
	}
}
