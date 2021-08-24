#include <nova/vec2.h>

#include <doctest/doctest.h>

TEST_CASE("[nova]: Vec2")
{
	SUBCASE("init")
	{
		nova::Vec2 v = {};
		CHECK(v.x == 0.0f);
		CHECK(v.y == 0.0f);

		v = {1.0f, 2.0f};
		CHECK(v.x == 1.0f);
		CHECK(v.y == 2.0f);
	}

	SUBCASE("equal")
	{
		nova::Vec2 a = { 1.0f,  2.0f};
		nova::Vec2 b = { 1.0f,  2.0f};
		nova::Vec2 c = {11.0f, 12.0f};

		CHECK(a == b);
		CHECK(a != c);
	}

	SUBCASE("add")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = {11.0f, 12.0f};

		nova::Vec2 c = a + b;
		CHECK(c.x == a.x + b.x);
		CHECK(c.y == a.y + b.y);

		a += b;
		CHECK(a == c);
	}

	SUBCASE("unary minus")
	{
		nova::Vec2 a = {1.0f, 2.0f};

		nova::Vec2 b = -a;
		CHECK(b.x == -a.x);
		CHECK(b.y == -a.y);
	}

	SUBCASE("subtract")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = {11.0f, 12.0f};

		nova::Vec2 c = a - b;
		CHECK(c.x == a.x - b.x);
		CHECK(c.y == a.y - b.y);

		a -= b;
		CHECK(a == c);
	}

	SUBCASE("multiply")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		float f = 5.0f;

		nova::Vec2 b = a * f;
		CHECK(b.x == a.x * f);
		CHECK(b.y == a.y * f);

		b = f * a;
		CHECK(b.x == a.x * f);
		CHECK(b.y == a.y * f);

		a *= f;
		CHECK(b == b);
	}

	SUBCASE("divide")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		float f = 5.0f;

		nova::Vec2 b = a / f;
		CHECK(b.x == a.x / f);
		CHECK(b.y == a.y / f);

		a /= f;
		CHECK(a == b);
	}

	SUBCASE("dot")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = {11.0f, 12.0f};

		CHECK(nova::dot(a, a) == 5.0f);
		CHECK(nova::dot(b, b) == 265.0f);
		CHECK(nova::dot(a, b) == 35.0f);

		nova::Vec2 a_normalized = nova::normalize(a);
		nova::Vec2 b_normalized = nova::normalize(b);

		CHECK(nova::dot(a_normalized, a_normalized) == doctest::Approx(1.0f));
		CHECK(nova::dot(b_normalized, b_normalized) == doctest::Approx(1.0f));
		CHECK(nova::dot(a_normalized, b_normalized) == doctest::Approx(0.962f).epsilon(0.001f));
	}

	SUBCASE("norm")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = {11.0f, 12.0f};

		float a_norm = nova::norm(a);
		float b_norm = nova::norm(b);

		CHECK(a_norm == doctest::Approx(2.236f).epsilon(0.001f));
		CHECK(b_norm == doctest::Approx(16.279f).epsilon(0.001f));
	}

	SUBCASE("length")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = {11.0f, 12.0f};

		float a_length = nova::length(a);
		float b_length = nova::length(b);

		CHECK(a_length == doctest::Approx(2.236f).epsilon(0.001f));
		CHECK(b_length == doctest::Approx(16.279f).epsilon(0.001f));
	}

	SUBCASE("normalize")
	{
		nova::Vec2 a = {1.0f, 2.0f};
		nova::Vec2 b = {11.0f, 12.0f};

		nova::Vec2 a_normalized = nova::normalize(a);
		nova::Vec2 b_normalized = nova::normalize(b);

		float a_length = nova::length(a_normalized);
		float b_length = nova::length(b_normalized);

		CHECK(a_length == doctest::Approx(1.0f));
		CHECK(b_length == doctest::Approx(1.0f));
	}

	SUBCASE("cross")
	{
		nova::Vec2 x = {1.0f, 0.0f};
		nova::Vec2 y = {0.0f, 1.0f};

		float xy = nova::cross(x, y);
		CHECK(xy == doctest::Approx(1.0f));

		float yx = nova::cross(y, x);
		CHECK(yx == doctest::Approx(-1.0f));
	}
}
