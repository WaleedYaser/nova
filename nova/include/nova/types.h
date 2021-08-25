#pragma once

#include "nova/defines.h"

NOVA_MSVC_SUPPRESS_WARNING_PUSH
NOVA_MSVC_SUPPRESS_WARNING(4201) // warning C4201: nonstandard extension used: nameless struct/union

namespace nova
{
	union Vec2
	{
		struct { float x, y; };
		struct { float u, v; };
		struct { float width, height; };
		float values[2];

		inline float &operator[](const int &index) { return values[index]; }
		inline const float &operator[](const int &index) const { return values[index]; }
	};

	union Vec3
	{
		struct { float x, y, z; };
		struct { float u, v, w; };
		struct { float r, g, b; };
		struct { float width, height, depth; };

		struct { Vec2 xy; float _z; };
		struct { float _x; Vec2 yz; };

		struct { Vec2 uv; float _w; };
		struct { float _u; Vec2 vw; };

		struct { Vec2 rg; float _b; };
		struct { float _r; Vec2 gb; };

		float values[3];

		inline float &operator[](const int &index) { return values[index]; }
		inline const float &operator[](const int &index) const { return values[index]; }
	};

	union Vec4
	{
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };

		struct { Vec3 xyz; float _w; };
		struct { float _x; Vec3 yzw; };

		struct { Vec3 rgb; float _a; };
		struct { float _r; Vec3 gba; };

		struct { Vec2 xy; float _zw[2]; };
		struct { float _x; Vec2 yz; float _w; };
		struct { float _xy[2]; Vec2 zw; };

		struct { Vec2 rg; float _ba[2]; };
		struct { float _r; Vec2 gb; float _a; };
		struct { float _rg[2]; Vec2 ba; };

		float values[4];

		inline float &operator[](const int &index) { return values[index]; }
		inline const float &operator[](const int &index) const { return values[index]; }
	};

	struct Mat2
	{
		Vec2 rows[2];

		inline Vec2 &operator[](const int &index) { return rows[index]; }
		inline const Vec2 &operator[](const int &index) const { return rows[index]; }
	};

	struct Mat3
	{
		Vec3 rows[3];

		inline Vec3 &operator[](const int &index) { return rows[index]; }
		inline const Vec3 &operator[](const int &index) const { return rows[index]; }
	};

	struct Mat4
	{
		Vec4 rows[4];

		inline Vec4 &operator[](const int &index) { return rows[index]; }
		inline const Vec4 &operator[](const int &index) const { return rows[index]; }
	};
}

NOVA_MSVC_SUPPRESS_WARNING_PUSH
