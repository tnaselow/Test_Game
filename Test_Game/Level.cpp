#include "Level.h"
#include <fstream>
#include <sstream>
#include "ResourceManager.h"

void Level::Load(const char *file, unsigned lvlWidth, unsigned lvlHeight)
{
	Bricks.clear();

	unsigned tileCode;

	Level level;
	std::string line;
	std::ifstream fstream(file);
	std::vector<std::vector<unsigned>> tileData;
	if (fstream)
	{
		while (std::getline(fstream, line))
		{
			std::istringstream sstream(line);
			std::vector<unsigned> row;
			while (sstream >> tileCode)
				row.push_back(tileCode);
			tileData.push_back(row);
		}
		if (tileData.size() > 0)
			Init(tileData, lvlWidth, lvlHeight);
	}

}

void Level::Init(const std::vector<std::vector<unsigned>> &tileData, unsigned lvlWidth, unsigned lvlHeight)
{
	unsigned height = tileData.size();
	unsigned width = tileData[0].size();

	float unitHeight = lvlHeight / static_cast<float>(height);
	float unitWidth = lvlWidth / static_cast<float>(width);

	for (unsigned y = 0; y < height; y++)
	{
		for (unsigned x = 0; x < width; x++)
		{
			if (tileData[y][x] == 1)
			{
				Entity entity;
				Transform *trans = entity.AddComponent<Transform>(TRANSFORM);
				Sprite *sprite = entity.AddComponent<Sprite>(SPRITE);

				trans->SetPosition(Vector3(unitWidth * x, unitHeight * y));
				trans->SetScale(Vector3(unitWidth, unitHeight));
				sprite->Texture = ResourceManager::GetTexture("block_solid");
				sprite->Color = Vector3(0.8f, 0.8f, 0.7f);
				Bricks.push_back(entity);
			}
			else if (tileData[y][x] > 1)
			{
				Entity entity;
				Transform *trans = entity.AddComponent<Transform>(TRANSFORM);
				Sprite *sprite = entity.AddComponent<Sprite>(SPRITE);

				trans->SetPosition(Vector3(unitWidth * x, unitHeight * y));
				trans->SetScale(Vector3(unitWidth, unitHeight));

				sprite->Texture = ResourceManager::GetTexture("block");
				switch (tileData[y][x])
				{
				case 2:
					sprite->Color = Vector3(0.2f, 0.6f, 1.0f);
					break;
				case 3:
					sprite->Color = Vector3(0.0f, 0.7f, 0.0f);
					break;
				case 4:
					sprite->Color = Vector3(0.8f, 0.8f, 0.4f);
					break;
				case 5:
					sprite->Color = Vector3(1.0f, 0.5f, 0.0f);
					break;
				default:
					sprite->Color = Vector3(1.0f, 1.0f, 1.0f);
					break;
				}
				Bricks.push_back(entity);
			}
		}
	}
}

void Level::Draw(Renderer renderer)
{
	for (unsigned i = 0; i < Bricks.size(); i++)
		Bricks[i].Draw();
};

bool Level::IsCompleted()
{
	return false;
}
