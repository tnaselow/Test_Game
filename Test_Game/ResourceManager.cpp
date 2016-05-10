#include "ResourceManager.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <SOIL\SOIL.h>

std::map<std::string, Shader>	ResourceManager::Shaders;
std::map<std::string, Texture2D>	ResourceManager::Textures;

Shader ResourceManager::LoadShader(std::string name, char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
	return Shaders[name];
}

Texture2D ResourceManager::LoadTexture(std::string name, const char *file, bool alpha)
{
	Textures[name] = loadTextureFromFile(file, alpha);
	return Textures[name];
}

Texture2D ResourceManager::GetTexture(std::string name)
{
	return Textures[name];
}

void ResourceManager::Clear()
{
	for (auto iter : Shaders)
		glDeleteProgram(iter.second.ID);
	for (auto iter : Textures)
		glDeleteTextures(1, &iter.second.ID);
}

Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderfile)
{
	std::string vertCode;
	std::string fragCode;
	std::string geomCode;

	try
	{
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		vertCode = vShaderStream.str();
		fragCode = fShaderStream.str();

		if (gShaderfile != nullptr)
		{
			std::ifstream geomShaderFile(gShaderfile);
			std::stringstream gShaderStream;

			gShaderStream << geomShaderFile.rdbuf();

			geomShaderFile.close();
			geomCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "Failed to read Shader Files" << std::endl;
	}

	const char *vShaderCode = vertCode.c_str();
	const char *fShaderCode = fragCode.c_str();
	const char *gShaderCode;
	if (gShaderfile == nullptr)
		gShaderCode = nullptr;
	else 
		gShaderCode = geomCode.c_str();

	Shader shader;
	try
	{
		shader.Compile(vShaderCode, fShaderCode, gShaderCode);
	}
	catch (std::string string)
	{
		std::cout << string << std::endl;
	}
	return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
	Texture2D texture;
	if (alpha)
	{
		texture.Internal_Format = GL_RGBA;
		texture.Image_Format = GL_RGBA;
	}

	int width, height;
	unsigned char *image = SOIL_load_image(file, &width, &height, 0, texture.Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

	texture.Generate(width, height, image);

	SOIL_free_image_data(image);
	return texture;
}