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
	ResourceManager::LoadTexture("block", "../res/block.png", false);
	ResourceManager::LoadTexture("block_solid", "../res/block_solid.png", false);
	ResourceManager::LoadTexture("background", "../res/background.jpg", false);

	level.Load("../levels/level_one.lvl", 800, 300);

	Entity entity;
	Transform *trans = entity.AddComponent<Transform>(TRANSFORM);
	trans->SetPosition(Vector3(0, 0));
	trans->SetScale(Vector3(100, 100));
	Sprite *sprite = entity.AddComponent<Sprite>(SPRITE);
	sprite->mTexture = ResourceManager::GetTexture("block");

	gEntities.push_back(entity);

	trans->SetPosition(Vector3(300, 100));
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
	renderer->DrawSprite(ResourceManager::GetTexture("background"), Vector3(0, 0), Vector3(800, 600));
	level.Draw(*renderer);
	//renderer->DrawSprite(ResourceManager::GetTexture("smile"), Vector3(400, 300), Vector3(400, 200));
}