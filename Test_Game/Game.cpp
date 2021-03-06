#include "Game.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Entity.h"
#include "Level.h"

Renderer *renderer;

Level level;

std::vector<Entity> gEntities;


Game::Game(unsigned width, unsigned height) : CurrentState(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}
Game::~Game()
{

}

void Game::Init()
{
	Entity entities[2];

	ResourceManager::LoadShader("default", "../shaders/default.vert", "../shaders/default.frag");
	ResourceManager::GetShader("default").SetInteger("image", 0);
	renderer = new Renderer(ResourceManager::GetShader("default"));

	ResourceManager::LoadTexture("smile", "../res/smile.png", true);
	ResourceManager::LoadTexture("block", "../res/oneTile.png", true);
	ResourceManager::LoadTexture("block_solid", "../res/grass2.png", true);
	ResourceManager::LoadTexture("background", "../res/background.jpg", false);

	level.Load("../levels/level_one.lvl", 800, 300);

	Entity entity;
	Transform *trans = entity.AddComponent<Transform>(COMPONENT_TRANSFORM);
	trans->setPosition(Vec2(0, 0));
	trans->setScale(Vec2(100, 100));
	Sprite *sprite = entity.AddComponent<Sprite>(COMPONENT_SPRITE);
	sprite->mTexture = ResourceManager::GetTexture("block");

	gEntities.push_back(entity);

	trans->setPosition(Vec2(300, 100));
	sprite->mTexture = ResourceManager::GetTexture("block_solid");

	gEntities.push_back(entity);
}

void Game::ProccessInput(float dt)
{

}
void Game::Update(float dt)
{

}

void Game::Render()
{
	//for (int i = 0; i < gEntities.size(); i++)
	//	gEntities[i].Draw();
	renderer->DrawSprite(ResourceManager::GetTexture("background"), Vec2(0, 0), Vec2(800, 600));
	level.Draw(*renderer);
	//renderer->DrawSprite(ResourceManager::GetTexture("smile"), Vector3(400, 300), Vector3(400, 200));
}