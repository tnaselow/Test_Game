#include "Game.h"
#include "ResourceManager.h"
#include "Renderer.h"

namespace
{
	Renderer *renderer;
}

Game::Game(unsigned width, unsigned height) : CurrentState(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}
Game::~Game()
{

}

void Game::Init()
{
	ResourceManager::LoadShader("default", "../shaders/default.vert", "../shaders/default.frag");
	ResourceManager::GetShader("default").SetInteger("image", 0);

	renderer = new Renderer(ResourceManager::GetShader("default"));
	ResourceManager::LoadTexture("smile", "../res/smile.png", true);
}

void Game::ProccessInput(float dt)
{

}
void Game::Update(float dt)
{

}

void Game::Render()
{
	renderer->DrawSprite(ResourceManager::GetTexture("smile"), Vector3(0, 0), Vector3(400, 200));
}