#include "Sprite.h"

#include "Renderer.h"
#include "ResourceManager.h"
#include "Entity.h"

// very temporary
extern Renderer *renderer;

void Sprite::Draw()
{
	Transform *trans = static_cast<Transform *>(Owner->GetComponent(TRANSFORM));
	renderer->DrawSprite(Texture, trans->GetPosition(), trans->GetScale(), trans->GetRotation(), Color);
}