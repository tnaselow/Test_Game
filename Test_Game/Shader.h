#pragma once

#define GLEW_STATIC

#include <string>

#include <GL\glew.h>
#include <Sapph\Vector3.h>
#include <Sapph\Matrix4.h>


class Shader
{
	public:
		unsigned ID;

		Shader() {};

		Shader &Use();
		void	Compile(const char *vertSource, const char *fragSource, const char *geomSource = nullptr);

		void	SetFloat(const char *name, float value, bool useShader = false);
		void    SetInteger(const char *name, int value, bool useShader = false);
		void    SetVector2f(const char *name, float x, float y, bool useShader = false);
		void    SetVector3f(const char *name, float x, float y, float z, float useShader = false);
		void    SetVector3f(const char *name, const Vector3 &value, bool useShader = false);
		void    SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false);
		void    SetMatrix4(const char *name, Matrix4 &matrix, bool useShader = false);

	private:
		void checkCompileErrors(unsigned object, std::string type);
};