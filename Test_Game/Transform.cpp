#include "Transform.h"


Component *Transform::clone()
{
	return new Transform(*this);
}

void Transform::setPosition(Vec2 vec)
{
	mPosition = vec;
	mChanged = true;
}

void Transform::setScale(Vec2 vec)
{
	mScale = vec;
	mChanged = true;
}

void Transform::setRotation(float rot)
{
	mRotation = rot;
	mChanged = true;
}

void Transform::update()
{
	if (mChanged)
	{
		Mat3 model;
		model.setScale(mScale);
		model.rotateDeg(mRotation);
		model.translate(mPosition);
		mModelMatrix = Mat4(model);
		mChanged = false;
	}
}