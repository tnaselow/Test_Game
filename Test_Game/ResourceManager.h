#pragma once

#define GLEW_STATIC

#include <map>
#include <string>

#include <GL\glew.h>

#include "Texture2D.h"
#include "Shader.h"

class ResourceManager
{
	public:
		static std::map<std::string, Shader>	Shaders;
		static std::map<std::string, Texture2D>	Textures;

		static Shader		LoadShader(std::string name, char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
		static Shader		GetShader(std::string name);

		static Texture2D	LoadTexture(std::string name, const char *file, bool alpha);
		static Texture2D	GetTexture(std::string name);

		static void Clear();
	private:
		ResourceManager() {}

		static Shader		loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderfile = nullptr);

		static Texture2D	loadTextureFromFile(const char *file, bool alpha);
};