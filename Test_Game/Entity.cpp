#include "Entity.h"


Entity::Entity() : mComponents(NUM_COMPONENTS)
{
	for (unsigned i = 0; i < mComponents.size(); i++)
		mComponents[i] = nullptr;
}

Entity::Entity(const Entity &entity) : mComponents(NUM_COMPONENTS)
{
	for (unsigned i = 0; i < mComponents.size(); i++)
		mComponents[i] = nullptr;
	*this = entity;
}

Entity::~Entity()
{
	for (unsigned i = 0; i < mComponents.size(); i++)
		if (mComponents[i] != nullptr)
		{
			delete mComponents[i];
			mComponents[i] = nullptr;
		}
}

void Entity::operator=(const Entity &entity)
{
	for (int i = 0; i < mComponents.size(); i++)
	{
		if (entity.mComponents[i] != nullptr)
		{
			mComponents[i] = entity.mComponents[i]->clone();
			mComponents[i]->mOwner = this;
		}
	}
}

void Entity::update()
{
	for (unsigned i = 0; i < mComponents.size(); i++)
		if (mComponents[i] != nullptr)
			mComponents[i]->update();
}

void Entity::draw()
{
	if (mComponents[SPRITE] != nullptr)
	{
		Sprite *sprite = static_cast<Sprite *>(mComponents[SPRITE]);
		sprite->draw();
	}
}
