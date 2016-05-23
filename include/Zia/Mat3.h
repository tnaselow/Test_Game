#pragma once
#include "Vec2.h"
#include <iostream>

class Mat3
{
	public:
		Mat3();
		Mat3(const Mat3 &mat);


		Vec2 operator *(const Vec2 &vec) const;
		Mat3 operator *(const Mat3 &mat) const;
		Mat3 operator *(float scalar) const;
		Mat3 &operator *=(const Mat3 &mat);
		Mat3 &operator *=(float scalar);
		Mat3 &operator=(const Mat3 &mat);
		bool operator==(const Mat3 &mat) const;

		Mat3 getTranspose();
		Mat3 getInverse();


		Mat3 &setScale(Vec2 scale); 
		Mat3 &setScale(float xScale, float yScale);

		Mat3 &setTranslate(float x, float y);
		Mat3 &setTranslate(const Vec2 &vec);
		Mat3 &setRotationDeg(float deg);
		Mat3 &setRotationRad(float rad);


		Mat3 &scale(Vec2 scale);
		Mat3 &scale(float xScale, float yScale);

		Mat3 &translate(Vec2 vec);
		Mat3 &translate(float x, float y);

		Mat3 &rotateDeg(float deg);
		Mat3 &rotateRad(float rad);

		Mat3 &setToTranspose();
		bool setToInverse();
		Mat3 &setToIdentity();

		Vec2 multiplyVec(const Vec2 &vec, float w = 0);

		const float getCell(int x, int y);

		void setOrtho(float left, float right, float bottom, float top, float near, float far);

		float *getMat4Data();
		const float *getMatrixData();

		friend std::ostream &operator<<(std::ostream &os, const Mat3 &mat);
	private:
		static const int WIDTH = 3;
		float mMatrix[9];
};