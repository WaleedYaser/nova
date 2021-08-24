#include <nova/vec4.h>

#include <doctest/doctest.h>

TEST_CASE("[nova]: Vec4")
{
	SUBCASE("init")
	{
		nova::Vec4 v = {};
		CHECK(v.x == 0);
		CHECK(v.y == 0);
		CHECK(v.z == 0);
		CHECK(v.w == 0);

		v = {1.0f, 2.0f, 3.0f, 4.0f};
		CHECK(v.x == 1.0f);
		CHECK(v.y == 2.0f);
		CHECK(v.z == 3.0f);
		CHECK(v.w == 4.0f);
	}

	SUBCASE("equal")
	{
		nova::Vec4 a = { 1.0f,  2.0f,  3.0f,  4.0f};
		nova::Vec4 b = { 1.0f,  2.0f,  3.0f,  4.0f};
		nova::Vec4 c = {11.0f, 12.0f, 13.0f, 14.0f};

		CHECK(a == b);
		CHECK(a != c);
	}

	SUBCASE("add")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		nova::Vec4 b = {11.0f, 12.0f, 13.0f, 14.0f};

		nova::Vec4 c = a + b;
		CHECK(c.x == a.x + b.x);
		CHECK(c.y == a.y + b.y);
		CHECK(c.z == a.z + b.z);
		CHECK(c.w == a.w + b.w);

		a += b;
		CHECK(a == c);
	}

	SUBCASE("unary minus")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};

		nova::Vec4 b = -a;
		CHECK(b.x == -a.x);
		CHECK(b.y == -a.y);
		CHECK(b.z == -a.z);
		CHECK(b.w == -a.w);
	}

	SUBCASE("subtract")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		nova::Vec4 b = {11.0f, 12.0f, 13.0f, 14.0f};

		nova::Vec4 c = a - b;
		CHECK(c.x == a.x - b.x);
		CHECK(c.y == a.y - b.y);
		CHECK(c.z == a.z - b.z);
		CHECK(c.w == a.w - b.w);

		a -= b;
		CHECK(a == c);
	}

	SUBCASE("multiply")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		float f = 5.0f;

		nova::Vec4 b = a * f;
		CHECK(b.x == a.x * f);
		CHECK(b.y == a.y * f);
		CHECK(b.z == a.z * f);
		CHECK(b.w == a.w * f);

		b = f * a;
		CHECK(b.x == a.x * f);
		CHECK(b.y == a.y * f);
		CHECK(b.z == a.z * f);
		CHECK(b.w == a.w * f);

		a *= f;
		CHECK(a == b);
	}

	SUBCASE("divide")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		float f = 5.0f;

		nova::Vec4 b = a / f;
		CHECK(b.x == a.x / f);
		CHECK(b.y == a.y / f);
		CHECK(b.z == a.z / f);
		CHECK(b.w == a.w / f);

		a /= f;
		CHECK(a == b);
	}

	SUBCASE("dot")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		nova::Vec4 b = {11.0f, 12.0f, 13.0f, 14.0f};

		CHECK(nova::dot(a, a) == 30.0f);
		CHECK(nova::dot(b, b) == 630.0f);
		CHECK(nova::dot(a, b) == 130.0f);

		nova::Vec4 a_normalized = nova::normalize(a);
		nova::Vec4 b_normalized = nova::normalize(b);

		CHECK(nova::dot(a_normalized, a_normalized) == doctest::Approx(1.0f));
		CHECK(nova::dot(b_normalized, b_normalized) == doctest::Approx(1.0f));
		CHECK(nova::dot(a_normalized, b_normalized) == doctest::Approx(0.946f).epsilon(0.001f));
	}

	SUBCASE("norm")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		nova::Vec4 b = {11.0f, 12.0f, 13.0f, 14.0f};

		float a_norm = nova::norm(a);
		float b_norm = nova::norm(b);

		CHECK(a_norm == doctest::Approx(5.477f).epsilon(0.001f));
		CHECK(b_norm == doctest::Approx(25.1f).epsilon(0.001f));
	}

	SUBCASE("length")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		nova::Vec4 b = {11.0f, 12.0f, 13.0f, 14.0f};

		float a_length = nova::length(a);
		float b_length = nova::length(b);

		CHECK(a_length == doctest::Approx(5.477f).epsilon(0.001f));
		CHECK(b_length == doctest::Approx(25.1f).epsilon(0.001f));
	}

	SUBCASE("normalize")
	{
		nova::Vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
		nova::Vec4 b = {11.0f, 12.0f, 13.0f, 14.0f};

		nova::Vec4 a_normalized = nova::normalize(a);
		nova::Vec4 b_normalized = nova::normalize(b);

		float a_length = nova::length(a_normalized);
		float b_length = nova::length(b_normalized);

		CHECK(a_length == doctest::Approx(1.0f));
		CHECK(b_length == doctest::Approx(1.0f));
	}
}
