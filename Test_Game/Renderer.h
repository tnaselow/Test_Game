#pragma once

#include "Shader.h"
#include <map>
#include <Sapph\Matrix4.h>
#include <Sapph\Vector3.h>
#include "Texture2D.h"

class Renderer
{
public:
	std::multimap<unsigned, int> sprites;
	Matrix4 Projection;

	Renderer(const Shader &shader);

	void DrawSprite(Texture2D &tex, Vector3 position, Vector3 size = Vector3(10.0f, 10.0f, 0.0f), float rotation = 0.0f, Vector3 color = Vector3(1.0f, 1.0f, 1.0f));
	void Draw();
	void Flush();

private:
	Shader shader;
	unsigned quadVAO;

	void initRenderData();
};