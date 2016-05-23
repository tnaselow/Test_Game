#pragma once

#include <iostream>

class Vec2
{
	public:
		Vec2(float x = 0, float y = 0);
		Vec2(const Vec2 &vec);
		
		void set(float x, float y);

		float dot(const Vec2 &vec) const;
		float magnitude() const;
		Vec2 &normalize();

		Vec2 &operator=(const Vec2 &vec);
		bool operator==(const Vec2 &vec);

		Vec2 &operator /=(float scalar);
		Vec2 &operator *=(float scalar);
		Vec2 &operator +=(const Vec2 &vec);
		Vec2 &operator -=(const Vec2 &vec);

		Vec2 operator /(float scalar) const;
		Vec2 operator *(float scalar) const;
		Vec2 operator +(const Vec2 &vec) const;
		Vec2 operator -(const Vec2 &vec) const;

		friend std::ostream &operator<<(std::ostream &os, const Vec2 &vec);

		float X, Y;
};