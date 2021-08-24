#pragma once

#include "nova/types.h"
#include "nova/math.h"

namespace nova
{
	inline static bool
	operator==(const Mat2 &A, const Mat2 &B)
	{
		return
			A[0][0] == B[0][0] && A[0][1] == B[0][1] &&
			A[1][0] == B[1][0] && A[1][1] == B[1][1];
	}

	inline static bool
	operator!=(const Mat2 &A, const Mat2 &B)
	{
		return !(A == B);
	}

	inline static Mat2
	operator+(const Mat2 &A, const Mat2 &B)
	{
		return Mat2{
			A[0][0] + B[0][0], A[0][1] + B[0][1],
			A[1][0] + B[1][0], A[1][1] + B[1][1]
		};
	}

	inline static Mat2 &
	operator+=(Mat2 &A, const Mat2 &B)
	{
		A = A + B;
		return A;
	}

	inline static Mat2
	operator-(const Mat2 &M)
	{
		return Mat2{
			-M[0][0], -M[0][1],
			-M[1][0], -M[1][1]
		};
	}

	inline static Mat2
	operator-(const Mat2 &A, const Mat2 &B)
	{
		return Mat2{
			A[0][0] - B[0][0], A[0][1] - B[0][1],
			A[1][0] - B[1][0], A[1][1] - B[1][1]
		};
	}

	inline static Mat2 &
	operator-=(Mat2 &A, const Mat2 &B)
	{
		A = A - B;
		return A;
	}

	inline static Mat2
	operator*(const Mat2 &M, float f)
	{
		return Mat2{
			M[0][0] * f, M[0][1] * f,
			M[1][0] * f, M[1][1] * f
		};
	}

	inline static Mat2
	operator*(float f, const Mat2 &M)
	{
		return M * f;
	}

	inline static Mat2 &
	operator*=(Mat2 &M, float f)
	{
		M = M * f;
		return M;
	}

	inline static Vec2
	operator*(const Vec2 &v, const Mat2 &M)
	{
		return Vec2{
			v.x * M[0][0] + v.y * M[1][0],
			v.x * M[0][1] + v.y * M[1][1]
		};
	}

	inline static Mat2
	operator*(const Mat2 &A, const Mat2 &B)
	{
		Mat2 C;

		C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
		C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];

		C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
		C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

		return C;
	}

	inline static Mat2
	operator/(const Mat2 &M, float f)
	{
		return M * 1.0f / f;
	}

	inline static Mat2
	operator/(float f, const Mat2 &M)
	{
		return M / f;
	}

	inline static Mat2 &
	operator/=(Mat2 &M, float f)
	{
		M = M / f;
		return M;
	}

	inline static Mat2
	mat2_identity()
	{
		return Mat2{
			1, 0,
			0, 1
		};
	}

	inline static Mat2
	mat2_rotation(float theta)
	{
		float c = cos(theta);
		float s = sin(theta);

		return Mat2{
			 c, s,
			-s, c
		};
	}

	inline static Mat2
	mat2_scaling(float sx, float sy)
	{
		return Mat2{
			sx,  0,
			 0, sy
		};
	}

	inline static Mat2
	mat2_scaling(const Vec2 &s)
	{
		return mat2_scaling(s.x, s.y);
	}

	inline static Mat2
	mat2_shearing_x(float s)
	{
		return Mat2{
			1, 0,
			s, 1
		};
	}

	inline static Mat2
	mat2_shearing_y(float s)
	{
		return Mat2{
			1, s,
			0, 1
		};
	}

	inline static Mat2
	transpose(const Mat2 &M)
	{
		return Mat2{
			M[0][0], M[1][0],
			M[0][1], M[1][1]
		};
	}

	inline static float
	trace(const Mat2 &M)
	{
		return M[0][0] + M[1][1];
	}

	inline static float
	det(const Mat2 &M)
	{
		return M[0][0] * M[1][1] - M[0][1] * M[1][0];
	}

	inline static bool
	invertible(const Mat2 &M)
	{
		return det(M) != 0.0f;
	}

	inline static Mat2
	inverse(const Mat2 &M)
	{
		float d = det(M);
		if (d == 0.0f)
			return Mat2{};

		return (1.0f / d) * Mat2{
			 M[1][1], -M[0][1],
			-M[1][0],  M[0][0]
		};
	}
}
