#pragma once

#include "nova/types.h"
#include "nova/math.h"

namespace nova
{
	inline static bool
	operator==(const Vec4 &a, const Vec4 &b)
	{
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	inline static bool
	operator!=(const Vec4 &a, const Vec4 &b)
	{
		return !(a == b);
	}

	inline static Vec4
	operator+(const Vec4 &a, const Vec4 &b)
	{
		return Vec4{a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
	}

	inline static Vec4 &
	operator+=(Vec4 &a, const Vec4 &b)
	{
		a = a + b;
		return a;
	}

	inline static Vec4
	operator-(const Vec4 &v)
	{
		return Vec4{-v.x, -v.y, -v.z, -v.w};
	}

	inline static Vec4
	operator-(const Vec4 &a, const Vec4 &b)
	{
		return Vec4{a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
	}

	inline static Vec4 &
	operator-=(Vec4 &a, const Vec4 &b)
	{
		a = a - b;
		return a;
	}

	inline static Vec4
	operator*(const Vec4 &v, float f)
	{
		return Vec4{v.x * f, v.y * f, v.z * f, v.w * f};
	}

	inline static Vec4
	operator*(float f, const Vec4 &v)
	{
		return v * f;
	}

	inline static Vec4 &
	operator*=(Vec4 &v, float f)
	{
		v = v * f;
		return v;
	}

	inline static Vec4
	operator/(const Vec4 &v, float f)
	{
		return v * (1.0f / f);
	}

	inline static Vec4 &
	operator/=(Vec4 &v, float f)
	{
		v = v / f;
		return v;
	}

	inline static float
	dot(const Vec4 &a, const Vec4 &b)
	{
		return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
	}

	inline static float
	norm(const Vec4 &v)
	{
		return sqrt(dot(v, v));
	}

	inline static float
	length(const Vec4 &v)
	{
		return norm(v);
	}

	inline static Vec4
	normalize(const Vec4 &v)
	{
		return v / length(v);
	}

}
