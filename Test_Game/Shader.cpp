#include "Shader.h"

Shader &Shader::Use()
{
	glUseProgram(ID);
	return *this;
}

void Shader::Compile(const char *vertSource, const char *fragSource, const char *geomSource)
{
	unsigned sVert, sFrag, sGeom;

	sVert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVert, 1, &vertSource, NULL);
	glCompileShader(sVert);
	checkCompileErrors(sVert, "Vertex Shader");

	sFrag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFrag, 1, &fragSource, NULL);
	glCompileShader(sFrag);
	checkCompileErrors(sFrag, "Fragment Shader");

	if (geomSource != nullptr)
	{
		sGeom = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeom, 1, &geomSource, NULL);
		glCompileShader(sGeom);
		checkCompileErrors(sGeom, "Geometry Shader");
	}

	this->ID = glCreateProgram();
	glAttachShader(this->ID, sVert);
	glAttachShader(this->ID, sFrag);
	if (geomSource != nullptr)
		glAttachShader(this->ID, sGeom);
	glLinkProgram(this->ID);
	checkCompileErrors(this->ID, "PROGRAM");

	glDeleteShader(sVert);
	glDeleteShader(sFrag);
	if (geomSource != nullptr)
		glDeleteShader(sGeom);
}

void Shader::SetFloat(const char *name, float value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetInteger(const char *name, int value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetVector2f(const char *name, float x, float y, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::SetVector2f(const char *name, const Vec2 &vec, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->ID, name), vec.X, vec.Y);
}

void Shader::SetVector3f(const char *name, float x, float y, float z, float useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::SetVector3f(const char *name, const Vec3 &value, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->ID, name), value.X, value.Y, value.Z);
}

void Shader::SetVector4f(const char *name, float x, float y, float z, float w, bool useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}

void Shader::SetMatrix4(const char *name, Mat4 &matrix, bool useShader)
{
	if (useShader)
		this->Use();
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, true, matrix.GetMatrixData());
}

void Shader::checkCompileErrors(unsigned object, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			throw(std::string("ERROR:: " + type + " Couldnt COMPILE! \n " + infoLog));
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			throw(std::string("ERROR:: " + type + " Couldnt LINK! \n " + infoLog));
		}
	}
}