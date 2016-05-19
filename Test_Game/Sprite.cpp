#include "Sprite.h"

#include "Renderer.h"
#include "ResourceManager.h"
#include "Entity.h"

// very temporary
extern Renderer *renderer;

void Sprite::Draw()
{
	Transform *trans = Owner->GetComponent<Transform>(TRANSFORM);
	renderer->DrawSprite(mTexture, trans->GetPosition(), trans->GetScale(), trans->GetRotation(), mColor);
}

Component *Sprite::clone()
{
	return new Sprite(*this);
}