#include "Sprite.h"

#include "Renderer.h"
#include "ResourceManager.h"
#include "Entity.h"

// very temporary
extern Renderer *renderer;

void Sprite::draw()
{
	Transform *trans = mOwner->GetComponent<Transform>(COMPONENT_TRANSFORM);
	renderer->DrawSprite(mTexture, trans->getPosition(), trans->getScale(), trans->getRotation(), mColor);
}

Component *Sprite::clone()
{
	return new Sprite(*this);
}