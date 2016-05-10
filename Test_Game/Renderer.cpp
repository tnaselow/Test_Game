#include "Renderer.h"


Renderer::Renderer(const Shader &shader)
{
	this->shader = shader;

	Projection.SetOrtho(0.0, 800, 600, 0, -1.0f, 1.0f);
	this->shader.Use();
	this->shader.SetMatrix4("projection", Projection);

	initRenderData();
}

void Renderer::DrawSprite(Texture2D &texture, Vector3 position, Vector3 size, float rotation, Vector3 color)
{
	this->shader.Use();
	Matrix4 model, translate, rotate, scale;
	translate.Translate(position);
	rotate.RotateDeg(rotation);
	scale.Scale(size.X, AXIS::X_AXIS);
	scale.Scale(size.Y, AXIS::Y_AXIS);

	model = translate * rotate * scale;

	this->shader.SetMatrix4("model", model);
	this->shader.SetVector3f("spriteColor", color);

	glActiveTexture(GL_TEXTURE0);
	texture.Bind();

	glBindVertexArray(this->quadVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void Renderer::initRenderData()
{
	GLuint VBO;
	GLfloat vertices[] = {
		// Pos      // Tex
		-0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 1.0f, 0.0f,

		0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 1.0f
	};

	glGenVertexArrays(1, &this->quadVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(this->quadVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}