#include <nova/vec3.h>

#include <doctest/doctest.h>

TEST_CASE("[nova]: Vec3")
{
	SUBCASE("init")
	{
		nova::Vec3 v = {};
		CHECK(v.x == 0);
		CHECK(v.y == 0);
		CHECK(v.z == 0);

		v = {1.0f, 2.0f, 3.0f};
		CHECK(v.x == 1.0f);
		CHECK(v.y == 2.0f);
		CHECK(v.z == 3.0f);
	}

	SUBCASE("equal")
	{
		nova::Vec3 a = { 1.0f,  2.0f,  3.0f};
		nova::Vec3 b = { 1.0f,  2.0f,  3.0f};
		nova::Vec3 c = {11.0f, 12.0f, 13.0f};

		CHECK(a == b);
		CHECK(a != c);
	}

	SUBCASE("add")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		nova::Vec3 b = {11.0f, 12.0f, 13.0f};

		nova::Vec3 c = a + b;
		CHECK(c.x == a.x + b.x);
		CHECK(c.y == a.y + b.y);
		CHECK(c.z == a.z + b.z);

		a += b;
		CHECK(a == c);
	}

	SUBCASE("unary minus")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};

		nova::Vec3 b = -a;
		CHECK(b.x == -a.x);
		CHECK(b.y == -a.y);
		CHECK(b.z == -a.z);
	}

	SUBCASE("subtract")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		nova::Vec3 b = {11.0f, 12.0f, 13.0f};

		nova::Vec3 c = a - b;
		CHECK(c.x == a.x - b.x);
		CHECK(c.y == a.y - b.y);
		CHECK(c.z == a.z - b.z);

		a -= b;
		CHECK(a == c);
	}

	SUBCASE("multiply")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		float f = 5.0f;

		nova::Vec3 b = a * f;
		CHECK(b.x == a.x * f);
		CHECK(b.y == a.y * f);
		CHECK(b.z == a.z * f);

		b = f * a;
		CHECK(b.x == a.x * f);
		CHECK(b.y == a.y * f);
		CHECK(b.z == a.z * f);

		a *= f;
		CHECK(a == b);
	}

	SUBCASE("divide")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		float f = 5.0f;

		nova::Vec3 b = a / f;
		CHECK(b.x == a.x / f);
		CHECK(b.y == a.y / f);
		CHECK(b.z == a.z / f);

		a /= f;
		CHECK(a == b);
	}

	SUBCASE("dot")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		nova::Vec3 b = {11.0f, 12.0f, 13.0f};

		CHECK(nova::dot(a, a) == 14.0f);
		CHECK(nova::dot(b, b) == 434.0f);
		CHECK(nova::dot(a, b) == 74.0f);

		nova::Vec3 a_normalized = nova::normalize(a);
		nova::Vec3 b_normalized = nova::normalize(b);

		CHECK(nova::dot(a_normalized, a_normalized) == doctest::Approx(1.0f));
		CHECK(nova::dot(b_normalized, b_normalized) == doctest::Approx(1.0f));
		CHECK(nova::dot(a_normalized, b_normalized) == doctest::Approx(0.949f).epsilon(0.001f));
	}

	SUBCASE("norm")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		nova::Vec3 b = {11.0f, 12.0f, 13.0f};

		float a_norm = nova::norm(a);
		float b_norm = nova::norm(b);

		CHECK(a_norm == doctest::Approx(3.742f).epsilon(0.001f));
		CHECK(b_norm == doctest::Approx(20.833f).epsilon(0.001f));
	}

	SUBCASE("length")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		nova::Vec3 b = {11.0f, 12.0f, 13.0f};

		float a_length = nova::length(a);
		float b_length = nova::length(b);

		CHECK(a_length == doctest::Approx(3.742f).epsilon(0.001f));
		CHECK(b_length == doctest::Approx(20.833f).epsilon(0.001f));
	}

	SUBCASE("normalize")
	{
		nova::Vec3 a = {1.0f, 2.0f, 3.0f};
		nova::Vec3 b = {11.0f, 12.0f, 13.0f};

		nova::Vec3 a_normalized = nova::normalize(a);
		nova::Vec3 b_normalized = nova::normalize(b);

		float a_length = nova::length(a_normalized);
		float b_length = nova::length(b_normalized);

		CHECK(a_length == doctest::Approx(1.0f));
		CHECK(b_length == doctest::Approx(1.0f));
	}

	SUBCASE("cross")
	{
		nova::Vec3 x = {1.0f, 0.0f, 0.0f};
		nova::Vec3 y = {0.0f, 1.0f, 0.0f};
		nova::Vec3 z = {0.0f, 0.0f, 1.0f};

		nova::Vec3 xy = nova::cross(x, y);
		CHECK(xy.x == doctest::Approx(z.x));
		CHECK(xy.y == doctest::Approx(z.y));
		CHECK(xy.z == doctest::Approx(z.z));

		nova::Vec3 yx = nova::cross(y, x);
		CHECK(yx.x == doctest::Approx(-z.x));
		CHECK(yx.y == doctest::Approx(-z.y));
		CHECK(yx.z == doctest::Approx(-z.z));

		nova::Vec3 yz = nova::cross(y, z);
		CHECK(yz.x == doctest::Approx(x.x));
		CHECK(yz.y == doctest::Approx(x.y));
		CHECK(yz.z == doctest::Approx(x.z));

		nova::Vec3 zy = nova::cross(z, y);
		CHECK(zy.x == doctest::Approx(-x.x));
		CHECK(zy.y == doctest::Approx(-x.y));
		CHECK(zy.z == doctest::Approx(-x.z));

		nova::Vec3 zx = nova::cross(z, x);
		CHECK(zx.x == doctest::Approx(y.x));
		CHECK(zx.y == doctest::Approx(y.y));
		CHECK(zx.z == doctest::Approx(y.z));

		nova::Vec3 xz = nova::cross(x, z);
		CHECK(xz.x == doctest::Approx(-y.x));
		CHECK(xz.y == doctest::Approx(-y.y));
		CHECK(xz.z == doctest::Approx(-y.z));
	}
}
