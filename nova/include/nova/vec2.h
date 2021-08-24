#pragma once

#include "nova/types.h"
#include "nova/math.h"

namespace nova
{
	inline static bool
	operator==(const Vec2 &a, const Vec2 &b)
	{
		return a.x == b.x && a.y == b.y;
	}

	inline static bool
	operator!=(const Vec2 &a, const Vec2 &b)
	{
		return !(a == b);
	}

	inline static Vec2
	operator+(const Vec2 &a, const Vec2 &b)
	{
		return Vec2{a.x + b.x, a.y + b.y};
	}

	inline static Vec2 &
	operator+=(Vec2 &a, const Vec2 &b)
	{
		a = a + b;
		return a;
	}

	inline static Vec2
	operator-(const Vec2 &v)
	{
		return Vec2{-v.x, -v.y};
	}

	inline static Vec2
	operator-(const Vec2 &a, const Vec2 &b)
	{
		return Vec2{a.x - b.x, a.y - b.y};
	}

	inline static Vec2 &
	operator-=(Vec2 &a, const Vec2 &b)
	{
		a = a - b;
		return a;
	}

	inline static Vec2
	operator*(const Vec2 &v, float f)
	{
		return Vec2{v.x * f, v.y * f};
	}

	inline static Vec2
	operator*(float f, const Vec2 &v)
	{
		return v * f;
	}

	inline static Vec2 &
	operator*=(Vec2 &v, float f)
	{
		v = v * f;
		return v;
	}

	inline static Vec2
	operator/(const Vec2 &v, float f)
	{
		return v * (1.0f / f);
	}

	inline static Vec2 &
	operator/=(Vec2 &v, float f)
	{
		v = v / f;
		return v;
	}

	inline static float
	dot(const Vec2 &a, const Vec2 &b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	inline static float
	norm(const Vec2 &v)
	{
		return sqrt(dot(v, v));
	}

	inline static float
	length(const Vec2 &v)
	{
		return norm(v);
	}

	inline static Vec2
	normalize(const Vec2 &v)
	{
		return v / length(v);
	}

	inline static float
	cross(const Vec2 &a, const Vec2 &b)
	{
		return (a.x * b.y - a.y * b.x);
	}
}
