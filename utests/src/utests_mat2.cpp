#include <nova/mat2.h>

#include <doctest/doctest.h>

TEST_CASE("[nova_math]: Mat2")
{
	SUBCASE("init")
	{
		nova::Mat2 M = {};

		CHECK(M[0][0] == 0.0f); CHECK(M[0][1] == 0.0f);
		CHECK(M[1][0] == 0.0f); CHECK(M[1][1] == 0.0f);

		M = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		CHECK(M[0][0] == 1.0f); CHECK(M[0][1] == 2.0f);
		CHECK(M[1][0] == 3.0f); CHECK(M[1][1] == 4.0f);
	}

	SUBCASE("equal")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 C = {
			11.0f, 12.0f,
			13.0f, 14.0f
		};

		CHECK(A == B);
		CHECK(A != C);
	}

	SUBCASE("add")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = {
			11.0f, 12.0f,
			13.0f, 14.0f
		};

		nova::Mat2 C = A + B;
		CHECK(C[0][0] == A[0][0] + B[0][0]); CHECK(C[0][1] == A[0][1] + B[0][1]);
		CHECK(C[1][0] == A[1][0] + B[1][0]); CHECK(C[1][1] == A[1][1] + B[1][1]);

		A += B;
		CHECK(A == C);
	}

	SUBCASE("unary minus")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = -A;
		CHECK(B[0][0] == -A[0][0]); CHECK(B[0][1] == -A[0][1]);
		CHECK(B[1][0] == -A[1][0]); CHECK(B[1][1] == -A[1][1]);
	}

	SUBCASE("subtract")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = {
			11.0f, 12.0f,
			13.0f, 14.0f
		};

		nova::Mat2 C = A - B;
		CHECK(C[0][0] == A[0][0] - B[0][0]); CHECK(C[0][1] == A[0][1] - B[0][1]);
		CHECK(C[1][0] == A[1][0] - B[1][0]); CHECK(C[1][1] == A[1][1] - B[1][1]);

		A -= B;
		CHECK(A == C);
	}

	SUBCASE("multiply scalar")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		float f = 5.0f;

		nova::Mat2 B = A * f;
		CHECK(B[0][0] == f * A[0][0]); CHECK(B[0][1] == f * A[0][1]);
		CHECK(B[1][0] == f * A[1][0]); CHECK(B[1][1] == f * A[1][1]);

		B = f * A;
		CHECK(B[0][0] == f * A[0][0]); CHECK(B[0][1] == f * A[0][1]);
		CHECK(B[1][0] == f * A[1][0]); CHECK(B[1][1] == f * A[1][1]);

		A *= f;
		CHECK(A == B);
	}

	SUBCASE("multiply vector")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Mat2 M = {
			11.0f, 12.0f,
			13.0f, 14.0f
		};

		nova::Vec2 b = a * M;
		CHECK(b.x == 37.0f);
		CHECK(b.y == 40.0f);
	}

	SUBCASE("multiply matrix")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = {
			11.0f, 12.0f,
			13.0f, 14.0f
		};

		nova::Mat2 C = A * B;
		CHECK(C[0][0] == 37.0f); CHECK(C[0][1] == 40.0f);
		CHECK(C[1][0] == 85.0f); CHECK(C[1][1] == 92.0f);
	}

	SUBCASE("divide")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		float f = 5.0f;

		nova::Mat2 C = A / f;
		CHECK(C[0][0] == A[0][0] / f); CHECK(C[0][1] == A[0][1] / f);
		CHECK(C[1][0] == A[1][0] / f); CHECK(C[1][1] == A[1][1] / f);

		A /= f;
		CHECK(A == C);
	}

	SUBCASE("identity")
	{
		nova::Mat2 I = nova::mat2_identity();
		CHECK(I[0][0] == 1.0f); CHECK(I[0][1] == 0.0f);
		CHECK(I[1][0] == 0.0f); CHECK(I[1][1] == 1.0f);

		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = a * I;
		CHECK(b.x == a.x);
		CHECK(b.y == a.y);

		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = I * A;
		CHECK(B[0][0] == A[0][0]); CHECK(B[0][1] == A[0][1]);
		CHECK(B[1][0] == A[1][0]); CHECK(B[1][1] == A[1][1]);

		B = A * I;
		CHECK(B == A);
	}

	SUBCASE("transpose")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = nova::transpose(A);
		CHECK(B[0][0] == A[0][0]); CHECK(B[0][1] == A[1][0]);
		CHECK(B[1][0] == A[0][1]); CHECK(B[1][1] == A[1][1]);
	}

	SUBCASE("trace")
	{
		nova::Mat2 M = {
			0.0f, 2.0f,
			3.0f, 4.0f
		};

		CHECK(nova::trace(M) == 4.0f);
	}

	SUBCASE("determinant")
	{
		nova::Mat2 I = nova::mat2_identity();
		CHECK(nova::det(I) == 1.0f);

		nova::Mat2 M = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		CHECK(nova::det(M) == -2.0f);
	}

	SUBCASE("invertible")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		CHECK(nova::invertible(A) == true);

		nova::Mat2 B = {
			1.0f, 1.0f,
			1.0f, 1.0f
		};

		CHECK(nova::invertible(B) == false);
	}

	SUBCASE("inverse")
	{
		nova::Mat2 A = {
			1.0f, 2.0f,
			3.0f, 4.0f
		};

		nova::Mat2 B = nova::inverse(A);

		nova::Mat2 C = A * B;
		CHECK(C[0][0] == 1.0f); CHECK(C[0][1] == 0.0f);
		CHECK(C[1][0] == 0.0f); CHECK(C[1][1] == 1.0f);

		C = B * A;
		CHECK(C[0][0] == 1.0f); CHECK(C[0][1] == 0.0f);
		CHECK(C[1][0] == 0.0f); CHECK(C[1][1] == 1.0f);

		nova::Vec2 a = {11.0f, 12.0f};
		nova::Vec2 b = a * A * B;
		CHECK(b.x == a.x);
		CHECK(b.y == a.y);
	}

	SUBCASE("rotation")
	{
		nova::Mat2 R = nova::mat2_rotation((float)nova::PI_DIV_2);
		nova::Vec2 a = {1.0f, 1.0f};

		nova::Vec2 b = a * R;
		CHECK(b.x == doctest::Approx(-a.x));
		CHECK(b.y == doctest::Approx(a.y));

		nova::Vec2 c = b * nova::inverse(R);
		CHECK(c.x == doctest::Approx(a.x));
		CHECK(c.y == doctest::Approx(a.y));
	}

	SUBCASE("scaling")
	{
		nova::Vec2 s = {10.0f, 20.0f};

		nova::Mat2 S = nova::mat2_scaling(s.x, s.y);
		nova::Vec2 a = {1.0f, 2.0f};

		nova::Vec2 b = a * S;
		CHECK(b.x == a.x * s.x);
		CHECK(b.y == a.y * s.y);

		S = nova::mat2_scaling(s);

		b = a * S;
		CHECK(b.x == a.x * s.x);
		CHECK(b.y == a.y * s.y);

		nova::Vec2 c = b * nova::inverse(S);
		CHECK(c.x == doctest::Approx(a.x));
		CHECK(c.y == doctest::Approx(a.y));
	}

	SUBCASE("shearing x")
	{
		float s = 10.0f;

		nova::Mat2 H = nova::mat2_shearing_x(s);
		nova::Vec2 a = {1.0f, 2.0f};

		nova::Vec2 b = a * H;
		CHECK(b.x == a.x + a.y*s);
		CHECK(b.y == a.y);

		nova::Vec2 c = b * nova::inverse(H);
		CHECK(c.x == doctest::Approx(a.x));
		CHECK(c.y == doctest::Approx(a.y));
	}

	SUBCASE("shearing y")
	{
		float s = 10.0f;

		nova::Mat2 H = nova::mat2_shearing_y(s);
		nova::Vec2 a = {1.0f, 2.0f};

		nova::Vec2 b = a * H;
		CHECK(b.x == a.x);
		CHECK(b.y == a.y + a.x*s);

		nova::Vec2 c = b * nova::inverse(H);
		CHECK(c.x == doctest::Approx(a.x));
		CHECK(c.y == doctest::Approx(a.y));
	}
}
