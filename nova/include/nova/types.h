#pragma once

// Detecting compiler version are taken from: https://github.com/cxxstuff/cxx_detect

#define NOVA_CLANG 0
#define NOVA_GCC   0
#define NOVA_MSVC  0

#define NOVA_MAKE_VER(MAJOR, MINOR, PATCH) ((MAJOR) * 10000000 + (MINOR) * 100000 + (PATCH))

#if defined(_MSC_VER) && defined(_MSC_FULL_VER)
	#undef NOVA_MSVC
	#if _MSC_VER == _MSC_FULL_VER / 10000
		#define NOVA_MSVC NOVA_MAKE_VER(_MSC_VER / 100, _MSC_VER % 100, _MSC_FULL_VER % 10000)
	#else
		#define NOVA_MSVC NOVA_MAKE_VER(_MSC_VER / 100, (_MSC_FULL_VER / 100000) % 100, _MSC_FULL_VER % 100000)
	#endif
#elif defined(__GNUC__) && defined(__GNUC_MINOR__) && defined(__GNUC_PATCHLEVEL__)
	#undef NOVA_GCC
	#define NOVA_GCC NOVA_MAKE_VER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__clang__) && defined(__clang_minor__)
	#undef NOVA_CLANG
	#define NOVA_CLANG NOVA_MAKE_VER(__clang_major__, __clang_minor__, __clang_patchlevel__)
#else
	#error "[nova/types.h] Unable to detect C/C++ compiler."
#endif

#if NOVA_MSVC
	#pragma warning( push )
	#pragma warning( disable : 4201 ) // warning C4201: nonstandard extension used: nameless struct/union
#elif NOVA_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored 4201
#endif

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

		struct { Vec2 xy; float _z; float _w; };
		struct { float _x; Vec2 yz; float _w; };
		struct { float _x; float _y; Vec2 zw; };

		struct { Vec2 rg; float _b; float _a; };
		struct { float _r; Vec2 gb; float _a; };
		struct { float _r; float _g; Vec2 ba; };

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

#if NOVA_MSVC
	#pragma warning( pop )
#elif NOVA_GCC
	#pragma GCC diagnostic pop
#endif
