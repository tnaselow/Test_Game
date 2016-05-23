#pragma once
#include "Vec3.h"
#include <iostream>

enum AXIS
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
	ALL_AXES
};

class Mat3;

class Mat4
{
public:

	static const int Width = 4;
	Mat4();
	Mat4(const Mat4 &mat);
	Mat4(Mat3 &mat);
	~Mat4();


	Vec3 operator *(const Vec3 &vec) const;
	Mat4 operator *(const Mat4 &mat) const;
	Mat4 operator *(float scalar) const;
	Mat4 &operator *=(const Mat4 &mat);
	Mat4 &operator *=(float scalar);
	Mat4 &operator=(const Mat4 &mat);
	bool operator==(const Mat4 &mat) const;

	Mat4 GetTranspose();
	Mat4 GetInverse();


	Mat4 &Scale(float scalar, AXIS axis = AXIS::ALL_AXES); 
	Mat4 &Translate(float x, float y, float z);
	Mat4 &Translate(const Vec3 &vec);
	Mat4 &SetRotationDeg(float deg, AXIS axis = AXIS::Z_AXIS);
	Mat4 &SetRotationRad(float rad, AXIS axis = AXIS::Z_AXIS);

	Mat4 &RotateDeg(float deg, AXIS axis = AXIS::Z_AXIS);
	Mat4 &RotateRad(float deg, AXIS axis = AXIS::Z_AXIS);

	Mat4 &SetToTranspose();
	bool SetToInverse();
	Mat4 &SetToIdentity();

	Vec3 MultiplyVec(const Vec3 &vec, float w = 0);

	const float *GetMatrixData();
	float GetCell(int x, int y);

	void SetOrtho(float left, float right, float bottom, float top, float near, float far);
	void SetPerspective(float fov, float aspectRatio, float nearPlane, float farPlane);

	friend std::ostream &operator<<(std::ostream &os, const Mat4 &mat);

private:
	float mMatrix[16];
};