#include "Transform.h"


Component *Transform::clone()
{
	return new Transform(*this);
}

void Transform::setPosition(Vector3 vec)
{
	mPosition = vec;
	mChanged = true;
}

void Transform::setScale(Vector3 vec)
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

		mModelMatrix = Matrix4().Translate(mPosition) * Matrix4().RotateDeg(mRotation) 
					* Matrix4().Scale(mScale.X, AXIS::X_AXIS) * Matrix4().Scale(mScale.Y, AXIS::Y_AXIS);

		mChanged = false;
	}
}