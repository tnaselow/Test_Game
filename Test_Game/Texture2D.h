#pragma once

#define GLEW_STATIC

#include <GL\glew.h>

class Texture2D
{
	public:
		unsigned ID;

		unsigned Width, Height;

		unsigned Internal_Format;
		unsigned Image_Format;

		unsigned Wrap_S;
		unsigned Wrap_T;
		unsigned Filter_Min;
		unsigned Filter_Max;

		Texture2D();

		void Generate(unsigned width, unsigned height, unsigned char *data);

		void Bind() const;
};