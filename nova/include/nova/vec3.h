#pragma once

#include "nova/types.h"
#include "nova/math.h"

namespace nova
{
	inline static bool
	operator==(const Vec3 &a, const Vec3 &b)
	{
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	inline static bool
	operator!=(const Vec3 &a, const Vec3 &b)
	{
		return !(a == b);
	}

	inline static Vec3
	operator+(const Vec3 &a, const Vec3 &b)
	{
		return Vec3{a.x + b.x, a.y + b.y, a.z + b.z};
	}

	inline static Vec3 &
	operator+=(Vec3 &a, const Vec3 &b)
	{
		a = a + b;
		return a;
	}

	inline static Vec3
	operator-(const Vec3 &v)
	{
		return Vec3{-v.x, -v.y, -v.z};
	}

	inline static Vec3
	operator-(const Vec3 &a, const Vec3 &b)
	{
		return Vec3{a.x - b.x, a.y - b.y, a.z - b.z};
	}

	inline static Vec3 &
	operator-=(Vec3 &a, const Vec3 &b)
	{
		a = a - b;
		return a;
	}

	inline static Vec3
	operator*(const Vec3 &v, float f)
	{
		return Vec3{v.x * f, v.y * f, v.z * f};
	}

	inline static Vec3
	operator*(float f, const Vec3 &v)
	{
		return v * f;
	}

	inline static Vec3 &
	operator*=(Vec3 &v, float f)
	{
		v = v * f;
		return v;
	}

	inline static Vec3
	operator/(const Vec3 &v, float f)
	{
		return v * (1.0f / f);
	}

	inline static Vec3 &
	operator/=(Vec3 &v, float f)
	{
		v = v / f;
		return v;
	}

	inline static float
	dot(const Vec3 &a, const Vec3 &b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z);
	}

	inline static float
	norm(const Vec3 &v)
	{
		return sqrt(dot(v, v));
	}

	inline static float
	length(const Vec3 &v)
	{
		return norm(v);
	}

	inline static Vec3
	normalize(const Vec3 &v)
	{
		return v / length(v);
	}

	inline static Vec3
	cross(const Vec3 &a, const Vec3 &b)
	{
		return Vec3{
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x};
	}
}
