#include "Shader.h"

Shader &Shader::Use()
{
	glUseProgram(ID);
	return *this;
}

void Shader::Compile(const char *vertSource, const char *fragSource, const char *geomSource = nullptr)
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

void Shader::SetFloat(const char *name, float value, bool useShader = false)
{
	if (useShader)
		this->Use();
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetInteger(const char *name, int value, bool useShader = false)
{
	if (useShader)
		this->Use();
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetVector2f(const char *name, float x, float y, bool useShader = false)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::SetVector3f(const char *name, float x, float y, float z, float useShader = false)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::SetVector3f(const char *name, const Vector3 &value, bool useShader = false)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->ID, name), value.X, value.Y, value.Z);
}

void Shader::SetVector4f(const char *name, float x, float y, float z, float w, bool useShader = false)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}

void Shader::SetMatrix4(const char *name, const Matrix4 &matrix, bool useShader = false)
{
	float *data = matrix.GetMatrixData();
	if (useShader)
		this->Use();
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, true, matrix.GetMatrixData());
}

	private:
		void checkCompileErrors(unsigned object, std::string type);