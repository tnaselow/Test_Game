#pragma once

#include <string>

#include <GL\glew.h>


class Shader
{
	public:
		unsigned ID;

		Shader() {};

		Shader &Use();
		void	Compile(const char *vertSource, const char *fragSource, const char *geomSource = nullptr);



	private:
		void checkCompileErrors(unsigned object, std::string type);
};