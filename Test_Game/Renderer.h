#pragma once

#include "Shader.h"
#include <map>
#include "Texture2D.h"

class Renderer
{
public:
	std::multimap<unsigned, int> sprites;
	Mat4 Projection;

	Renderer(const Shader &shader);

	void DrawSprite(Texture2D &tex, Vec2 position, Vec2 size = Vec2(10.0f, 10.0f), float rotation = 0.0f, Vec3 color = Vec3(1.0f, 1.0f, 1.0f));
	void Draw();
	void Flush();

private:
	Shader shader;
	unsigned quadVAO;

	void initRenderData();
};