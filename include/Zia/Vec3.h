#pragma once
#include <iostream>

class Vec3
{
public:
	Vec3(float x = 0, float y = 0, float z = 0);
	Vec3(const Vec3 &vec);
	~Vec3();

	void Set(float x, float y, float z);

	float Dot(const Vec3 &vec) const;
	float Magnitude() const;
	Vec3 Cross(const Vec3 &vec) const;
	Vec3 &Scale(float scalar);
	Vec3 &Normalize();

	Vec3 &operator=(const Vec3 &vec);
	bool operator==(const Vec3 &vec);

	Vec3 &operator /=(float scalar);
	Vec3 &operator *=(float scalar);
	Vec3 &operator +=(const Vec3 &vec);
	Vec3 &operator -=(const Vec3 &vec);

	Vec3 operator /(float scalar) const;
	Vec3 operator *(float scalar) const;
	Vec3 operator +(const Vec3 &vec) const;
	Vec3 operator -(const Vec3 &vec) const;

	friend std::ostream &operator<<(std::ostream &os, const Vec3 &vec);

	float X, Y, Z;
};