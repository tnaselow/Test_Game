#include "Transform.h"


Component *Transform::clone()
{
	return new Transform(*this);
}

void Transform::SetPosition(Vector3 vec)
{
	Position = vec;
	changed = true;
}

void Transform::SetScale(Vector3 vec)
{
	Scale = vec;
	changed = true;
}

void Transform::SetRotation(float rot)
{
	Rotation = rot;
	changed = true;
}

void Transform::Update()
{
	if (changed)
	{

		ModelMatrix = Matrix4().Translate(Position) * Matrix4().RotateDeg(Rotation) 
					* Matrix4().Scale(Scale.X, AXIS::X_AXIS) * Matrix4().Scale(Scale.Y, AXIS::Y_AXIS);

		changed = false;
	}
}