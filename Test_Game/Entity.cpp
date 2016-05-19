#include "Entity.h"

namespace
{
	void CopyComponent(Component *newComp, const Component *cpyComp)
	{
		switch (newComp->GetType())
		{
		case SPRITE:
			*static_cast<Sprite *>(newComp) = *static_cast<const Sprite *>(cpyComp);
			break;
		case TRANSFORM:
			*static_cast<Transform *>(newComp) = *static_cast<const Transform *>(cpyComp);
			break;
		}
	}
}

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

Component *Entity::GetComponent(ComponentType type)
{
	return components[type];
}

Component *Entity::AddComponent(ComponentType type)
{
	if (components[type] == nullptr)
	{
		switch (type)
		{
		case SPRITE:
			components[type] = new Sprite();
			break;
		case TRANSFORM:
			components[type] = new Transform();
			break;
		}
		components[type]->Owner = this;
		return components[type];
	}
	else
		return nullptr;
}

void Entity::operator=(const Entity &entity)
{
	for (unsigned i = 0; i < components.size(); i++)
	{
		if (entity.components[i] != nullptr)
		{
			AddComponent(entity.components[i]->GetType());
			CopyComponent(components[i], entity.components[i]);
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
